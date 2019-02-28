cmake_minimum_required(VERSION 3.1)

project(optimization-test-functions CXX)
set(CMAKE_CXX_STANDARD 11)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/optimization-test-functions.hpp DESTINATION include)

add_library(optimization-test-functions INTERFACE)
target_sources(optimization-test-functions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/optimization-test-functions.hpp)
target_include_directories(optimization-test-functions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
