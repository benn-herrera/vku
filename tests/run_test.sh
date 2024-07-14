#!/usr/bin/env bash
THIS_SCRIPT=$(basename "${0}")
THIS_DIR=$(dirname "${0}")
# can't rely on realpath existing
THIS_DIR=$(cd "${THIS_DIR}"; pwd)

# accept from arg1 or existing envar
VK_VERSION=${1:-${VK_VERSION:-""}}

function usage() {
  cat << __EOF 1>&2
usage: ${THIS_SCRIPT} v<M.m.p>
  e.g. ${THIS_SCRIPT} v1.3.280
  use v0.0.0 for development iteration.
__EOF
  exit ${1}
}

case "${VK_VERSION}" in
  "v0.0.0") IS_DEV=true;;
  v*) IS_DEV=false;;
  *) usage 1;;
esac

cd "${THIS_DIR}"
set -eu
{
  test -f "../Vulkan-Headers/include/vulkan/vulkan.h" &&
  test -f "../${VK_VERSION}/include/vku/vku.h"
} || (echo "run gen_vku.sh first." 1>&2 && false)

function gen() {
  (/bin/rm -rf build 2> /dev/null; exit 0)
  mkdir -p build
  if (cd build && cmake .. -DVK_VERSION="${VK_VERSION}" "${@}" 2>&1) > build/gen.log; then
    return 0
  fi
  cat build/gen.log 1>&2
  return 1
}

function build() {
  if (cd build && cmake --build . 2>&1) > build/build.log; then
    return 0
  fi
  cat build/build.log 1>&2
  return 1
}

function run() {
  local cfg_dir=""
  if [[ -d build/bin/Debug ]]; then
    cfg_dir="/Debug"
  fi
  ./build/bin${cfg_dir:-""}/test
}

function gen_build_run() {
  gen "${@}" && build && run
}

set -x

gen -DVKU_IMPLEMENTATION_MACRO=VKU_IMPLEMENT
if (build 2> /dev/null); then
  echo "multiple uses of VKU_IMPLEMENT should not build successfully." 1>&2
  exit 1
fi
echo "Multiple uses of VKU_IMPLEMENT correctly failed to build."

gen_build_run -DVKU_IMPLEMENTATION_MACRO=VKU_INLINE_ALL -DCMAKE_CXX_STANDARD=11

gen_build_run -DVKU_IMPLEMENTATION_MACRO=VKU_INLINE_ALL -DCMAKE_CXX_STANDARD=17

gen_build_run -DVKU_IMPLEMENTATION_MACRO=VKU_INLINE_ALL -DCMAKE_CXX_STANDARD=20
