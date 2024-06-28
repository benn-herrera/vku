cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug)

project(integration_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT VK_VERSION)
    message(FATAL_ERROR "-DVK_VERSION=M.m.p must be specified on the cmake command line.")
endif()

set(VKU_INCLUDE "${PROJECT_SOURCE_DIR}/../${VK_VERSION}/include")

include_directories(
  ${VKU_INCLUDE}
  ${PROJECT_SOURCE_DIR}/../Vulkan-Headers/include)

add_executable(test integration.cpp ${VKU_INCLUDE}/vku/vku.h)
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(test)
