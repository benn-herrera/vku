#!/usr/bin/env bash
THIS_SCRIPT=$(basename "${0}")
THIS_DIR=$(dirname "${0}")
# can't rely on realpath existing
THIS_DIR=$(cd "${THIS_DIR}"; pwd)

DEFAULT_SDK_VER=$(
  awk '
  /^[ \t]*set\([ \t]*VKU_VERSION[ \t]+[0-9]+\.[0-9]+\.[0-9]+[ \t]*\)/ {
    gsub(/\(|\)/, "", $0); print($NF); exit(0);
  }
  ' "${THIS_DIR}/CMakeLists.txt"
)
VK_HEADERS_NAME="Vulkan-Headers"
VK_HEADERS_REPO="https://github.com/KhronosGroup/${VK_HEADERS_NAME}.git"

function usage() {
    echo "usage: ${THIS_SCRIPT} [--help] | [--auto-commit] [sdk-version]"
    echo "    where sdk-version is MAJ.min[.patch][.fix] e.g. 1.3 or 1.3.283 or 1.3.283.0"
    echo "    version must match a tagged version in ${VK_HEADERS_REPO}"
    echo "    when multiple tags match the most recent version is taken."
    echo "    priority is given to sdk release tags (vulkan-sdk-M,m.p.f)"
    echo "    if you need a newer version than the last sdk tagged version use the full M.m.p.f version"
    echo "    default is ${DEFAULT_SDK_VER}"
    echo "    use version 0.0.0 for development iteration of vku scripts and tests."
    exit ${1}
}

AUTO_COMMIT=false
VK_SDK_VER=${DEFAULT_SDK_VER}

while [[ -n "${1}" ]]; do
  opt=${1}
  shift
  if [[ "${opt/=/}" != "${opt}" ]]; then
    arg=${opt%=*}
    opt=${opt/*=/}
  else
    arg=""
  fi
  case "${opt}" in
    [0-9]*\.[0-9]*) VK_SDK_VER=${opt};;
    --auto-commit|-a) AUTO_COMMIT=true;;
    -h*|--h*|-u*|--u*) usage 0;;
    *) usage 1;;
  esac
done

case "${VK_SDK_VER}" in
  0*) VK_SDK_VER="0.0.0"; IS_DEV=true; DEV_MODE="DEV MODE ";;
  *) IS_DEV=false; DEV_MODE="";;
esac

if [[ ! -x "${PYTHON}" ]]; then
  if ! PYTHON=$(which python3 2> /dev/null); then
    if ! PYTHON=$(which python 2> /dev/null); then
      echo "python3 or python must be in path with version >= 3.11" 1>&2
      exit 1
    fi
  fi
fi
PY_VER=$(${PYTHON} --version | awk '{print $2;}')
PY_VER=${PY_VER%.*}
PY_MAJ_VER=${PY_VER%.*}
PY_MIN_VER=${PY_VER/*./}
if [[ ${PY_MAJ_VER:-0} -lt 3 || ${PY_MIN_VER:-0} -lt 11 ]]; then
  echo "python 3.11 required. ${PYTHON} is version ${PY_VER}" 1>&2
  exit 1
fi

GEN_VKU_PY="${THIS_DIR}/impl/gen_vku.py"
VK_HEADERS_SANDBOX="${THIS_DIR}/${VK_HEADERS_NAME}"
VK_XML="${VK_HEADERS_SANDBOX}/registry/vk.xml"

set -eu

if [[ ! -d "${VK_HEADERS_SANDBOX}" ]]; then
  git clone "${VK_HEADERS_REPO}" "${VK_HEADERS_SANDBOX}"
fi

(cd "${VK_HEADERS_SANDBOX}" && git fetch --tags)

if ${IS_DEV}; then
  VK_HEADERS_TAG=$(cd "${VK_HEADERS_SANDBOX}" && git tag | grep -e "${DEFAULT_SDK_VER//\./\\.}" | sort -Vr | head -1)
  (cd "${VK_HEADERS_SANDBOX}" && git -c advice.detachedHead=false checkout "${VK_HEADERS_TAG}")
  VK_HEADERS_TAG="v0.0.0"
else
  VK_HEADERS_TAG=$(cd "${VK_HEADERS_SANDBOX}" && git tag | grep -e "${VK_SDK_VER//\./\\.}" | sort -Vr | head -1)
  (cd "${VK_HEADERS_SANDBOX}" && git -c advice.detachedHead=false checkout "${VK_HEADERS_TAG}")
fi

test -r "${VK_XML}" || (echo "${VK_XML} missing." 1>&2 && false)

# normalize tags (vulkan-sdk-M.m.p.f and vM.m.p become vM.m.p)
# just the digits and dots
VK_VERSION="${VK_HEADERS_TAG//[^0-9.]/}"
# prepend v and strip the fix number. most recent fix version should always prevail.
VK_VERSION=$(set ${VK_VERSION//\./ }; echo "v${1}.${2}.${3}")
VKU_H="${THIS_DIR}/${VK_VERSION}/include/vku/vku.h"

echo "${DEV_MODE}generating ${VKU_H}..."
"${PYTHON}" "${GEN_VKU_PY}" "${VK_XML}" "${VKU_H}"
echo "${DEV_MODE}success."

function noop() {
    echo > /dev/null
}

if ${AUTO_COMMIT:-false}; then
  echo "${DEV_MODE}testing and auto committing."
  VK_VERSION="${VK_VERSION}" ./tests/run_test.sh
  if ${IS_DEV}; then
    DRY_RUN="echo DRY RUN "
    SETX=noop
  else
    DRY_RUN=
    SETX="set -x"
  fi
  (
    ${SETX} &&
    ${DRY_RUN} git add "${VKU_H}" &&
    ${DRY_RUN} git commit -m "generated vku.h"
  )
  echo "${DEV_MODE}push changes to finalize new vku.h"
else
  echo "${DEV_MODE}done."
fi
