cmake_minimum_required(VERSION 2.8)

project(HelloWorldConsole)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake")
set(CMAKE_DEBUG_POSTFIX "_d")
set(BUILD_DIR "__build")

set(SOURCES
    stdneb.cc 
    main.cc)

include(cotire)

include_directories("${PROJECT_SOURCE_DIR}/../../foundation")
link_directories("${PROJECT_SOURCE_DIR}/../../foundation/${BUILD_DIR}")

add_executable(HelloWorldConsole main.cc stdneb.cc)
target_link_libraries(HelloWorldConsole foundation${CMAKE_DEBUG_POSTFIX})
set_target_properties(HelloWorldConsole PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdneb.h")
cotire(HelloWorldConsole)
