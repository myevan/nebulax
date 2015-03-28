cmake_minimum_required(VERSION 2.8)

project(HelloWorldTests)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")

include(xplatform)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/../foundation")

link_directories("${PROJECT_SOURCE_DIR}/${BUILD_DIR}")
link_directories("${PROJECT_SOURCE_DIR}/../foundation/${BUILD_DIR}")

add_library(NebulaXTestBase
    testbase/testcase.cc
    testbase/testcase.h
    testbase/testrunner.cc
    testbase/testrunner.h)

add_executable(NebulaXTestFoundation
    testfoundation/main.cc
    testfoundation/stringtest.cc)

target_link_libraries(NebulaXTestFoundation 
    NebulaXFoundation${CMAKE_DEBUG_POSTFIX} 
    NebulaXTestBase${CMAKE_DEBUG_POSTFIX})
