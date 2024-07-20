cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(vku LANGUAGES NONE)

set(VKU_VERSION 1.3.283)

set(VKU_H "${CMAKE_CURRENT_SOURCE_DIR}/v${VKU_VERSION}/include/vku/vku.h")

add_library(
  vku 
  INTERFACE 
  ${VKU_H}
)

set_target_properties(
  vku
  PROPERTIES
  PUBLIC_HEADER ${VKU_H}
  )

install(TARGETS vku DESTINATION vku)
