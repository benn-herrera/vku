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
  "") usage 1;;
  *) IS_DEV=false;;
esac

cd "${THIS_DIR}"
set -eu
{
  test -f "../Vulkan-Headers/include/vulkan/vulkan.h" &&
  test -f "../${VK_VERSION}/include/vku/vku.h"
} || (echo "run gen_vku.sh first." 1>&2 && false)

# testing for real start with a clean slate

set -x
(/bin/rm -rf build 2>&1 > /dev/null; exit 0)
mkdir -p build
(cd build && cmake .. -DVK_VERSION="${VK_VERSION}" -DVKU_IMPLEMENTATION_MACRO=VKU_IMPLEMENT)
if (cd build && cmake --build . 2>&1 > /dev/null); then
  echo "multiple uses of VKU_IMPLEMENT should not build successfully." 1>&2
  exit 1
fi
echo "Multiple uses of VKU_IMPLEMENT correctly failed to build."

(/bin/rm -rf build 2>&1 > /dev/null; exit 0)
mkdir -p build
(cd build && cmake .. -DVK_VERSION="${VK_VERSION}" -DVKU_IMPLEMENTATION_MACRO=VKU_INLINE_ALL)
(cd build && cmake --build .)

if [[ -d build/bin/Debug ]]; then
  CFG_DIR="/Debug"
fi
./build/bin${CFG_DIR:-""}/test
