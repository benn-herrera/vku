#!/usr/bin/env bash
THIS_SCRIPT=$(basename "${0}")
THIS_DIR=$(dirname "${0}")
# can't rely on realpath existing
THIS_DIR=$(cd "${THIS_DIR}"; pwd)

cd "${THIS_DIR}"

VK_HEADERS_NAME="Vulkan-Headers"
VK_HEADERS_SANDBOX="${THIS_DIR}/../${VK_HEADERS_NAME}"

test -d "${VK_HEADERS_SANDBOX}" && (echo "run gen_vku.sh first." 1>&2 && false)

if [[ "${1}" == "--dev" ]]; then
  VK_VERSION="v0.0.0"
fi

if [[ ! -n "${VK_VERSION}" ]]; then
  VK_HEADERS_TAG=$(
    cd "${VK_HEADERS_SANDBOX}" &&
    git describe --tag | grep -e "${VK_SDK_VER//\./\\.}" | sort -Vr | head -1
    )
  VK_VERSION="${VK_HEADERS_TAG//[^0-9.]/}"
  # prepend v and strip the fix number. most recent fix version should always prevail.
  VK_VERSION=$(set ${VK_VERSION//\./ }; echo "v${1}.${2}.${3}")
fi

if [[ "${VK_VERSION}" != "v0.0.0" && -d build ]]; then
  /bin/rm -rf build
fi

set -eux

mkdir -p build
(cd build && cmake .. -DVK_VERSION="${VK_VERSION}")

(cd build && cmake --build .)

if [[ -d build/bin/Debug ]]; then
  TEST="./build/bin/Debug/test"
else
  TEST="./build/bin//test"
fi
"${TEST}"
