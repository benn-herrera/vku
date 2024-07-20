#!/usr/bin/env bash

#
# this is more an example than a utility.
# cmake install target is primarily for making it easy
# to import into other projects
#

GENERATOR=
if (which ninja 2>&1) > /dev/null; then
  GENERATOR="-G Ninja"
fi

mkdir -p build && \
cd build && \
cmake ${GENERATOR} "${@}" .. && \
cmake --build . --target install
