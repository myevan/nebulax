cmake_minimum_required(VERSION 2.8)

project(NebulaXTutorials)

if(NOT CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")
endif()

add_subdirectory(01_hello_world_console)

