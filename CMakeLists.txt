cmake_minimum_required(VERSION 3.10)
project(ZCrypt VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /source-charset:utf-8")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /execution-charset:utf-8")

# Add source files
include_directories(include)

add_subdirectory(src)