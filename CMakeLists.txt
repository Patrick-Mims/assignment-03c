cmake_minimum_required(VERSION 3.20)

project(dictionary VERSION 1.0)

include_directories("inc")

configure_file("${PROJECT_SOURCE_DIR}/src/config.h.in" "${PROJECT_BINARY_DIR}/config.h")
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB SOURCES "src/main.cc")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(${PROJECT_NAME} ${SOURCES})