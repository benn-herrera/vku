#!/usr/bin/env bash
THIS_DIR=$(dirname "${0}")
# can't rely on realpath existing
THIS_DIR=$(cd "${THIS_DIR}"; pwd)

if ! PYTHON=$(which python3 2> /dev/null); then
  if ! PYTHON=$(which python 2> /dev/null); then
    echo "python3 or python must be in path with version >= 3.11" 1>&2
    exit 1
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

VK_HEADERS_NAME="Vulkan-Headers"
VK_HEADERS_REPO="https://github.com/KhronosGroup/${VK_HEADERS_NAME}.git"
VK_SDK_VER="1.3.283.0"
VK_HEADERS_TAG="vulkan-sdk-${VK_SDK_VER}"

GEN_VKU_PY="${THIS_DIR}/gen_vku.py"
VK_HEADERS_SANDBOX="${THIS_DIR}/${VK_HEADERS_NAME}"
VK_XML="${THIS_DIR}/${VK_HEADERS_NAME}/registry/vk.xml"
VKU_H="${THIS_DIR}/${VK_SDK_VER}/vku.h"

set -eux

if [[ ! -d "${VK_HEADERS_SANDBOX}" ]]; then
  git clone "${VK_HEADERS_REPO}" "${VK_HEADERS_SANDBOX}"
fi
(
  cd "${VK_HEADERS_SANDBOX}" &&
    git fetch  &&
    git -c advice.detachedHead=false checkout "${VK_HEADERS_TAG}"
)
test -r "${VK_XML}" || (echo "${VK_XML} missing." 1>&2 && false)
"${PYTHON}" "${GEN_VKU_PY}" "${VK_XML}" "${VKU_H}"
