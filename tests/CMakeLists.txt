cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug)

project(integration_test LANGUAGES CXX)

if(NOT VK_VERSION)
    message(FATAL_ERROR "-DVK_VERSION=v<M>.<m>.<p> e.g. v1.2.260 must be specified on the cmake command line.")
endif()

message("CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}")

set(VKU_INCLUDE "${PROJECT_SOURCE_DIR}/../${VK_VERSION}/include")
set(VK_INCLUDE "${PROJECT_SOURCE_DIR}/../Vulkan-Headers/include")

include_directories(
  "${VKU_INCLUDE}"
  "${VK_INCLUDE}")

file(GLOB SOURCES "*.cpp")

add_executable(test
    ${SOURCES}
    test.h
    "${VKU_INCLUDE}/vku/vku.h"
    "${VK_INCLUDE}/vulkan/vulkan.h"
 )
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set_property(DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT test)

add_compile_definitions(${VKU_IMPLEMENTATION_MACRO})

target_link_libraries(test)
