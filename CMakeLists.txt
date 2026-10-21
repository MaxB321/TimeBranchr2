cmake_minimum_required(VERSION 4.3)

set(PROJ_NAME TimeBranchr)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJ_NAME} ${SOURCES})

target_include_directories(${PROJ_NAME} PRIVATE headers)
