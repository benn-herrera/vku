cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug)

project(integration_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT VK_VERSION)
    set(VK_VERSION "v1.2.3")
    set(VKU_INCLUDE "${PROJECT_SOURCE_DIR}/tmp/${VK_VERSION}/include")
 else()
    set(VKU_INCLUDE "${PROJECT_SOURCE_DIR}/../${VK_VERSION}/include")
endif()

include_directories(
  ${VKU_INCLUDE}
  ${PROJECT_SOURCE_DIR}/../Vulkan-Headers/include)

add_executable(test integration.cpp ${VKU_INCLUDE}/vku/vku.h)
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(test)
