cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)
project(integration_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT VK_VERSION)
  set(VK_VERSION "debug/v1.2.3")
endif()

include_directories(
  ${PROJECT_SOURCE_DIR}/../${VK_VERSION}/include 
  ${PROJECT_SOURCE_DIR}/../Vulkan-Headers/include)

add_executable(test integration.cpp ../${VK_VERSION}/include/vku/vku.h)

target_link_libraries(test)
