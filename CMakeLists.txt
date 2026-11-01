cmake_minimum_required(VERSION 4.3)

set(PROJ_NAME TimeBranchr2)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJ_NAME} ${SOURCES})

target_include_directories(${PROJ_NAME} PRIVATE 
    headers
    external_dependencies
)

target_precompile_headers(${PROJ_NAME} PRIVATE
    headers/pch.h
)
