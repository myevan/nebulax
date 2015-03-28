cmake_minimum_required(VERSION 3.0.2)

project(NebulaX)

option(N_BUILD_TESTS "Build Tests" ON)
option(N_BUILD_TUTORIALS "Build Tutorials" ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cotire)
include(xplatform)
include(nebulax)

add_subdirectory(foundation)

if(N_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(N_BUILD_TUTORIALS)
    add_subdirectory(tutorials)
endif()
