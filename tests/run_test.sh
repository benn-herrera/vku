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
if ! ${IS_DEV}; then
  /bin/rm -rf build
fi

set -x
mkdir -p build
(cd build && cmake .. -DVK_VERSION="${VK_VERSION}")
(cd build && cmake --build .)

if [[ -d build/bin/Debug ]]; then
  CFG_DIR="/Debug"
fi
./build/bin${CFG_DIR:-""}/test
