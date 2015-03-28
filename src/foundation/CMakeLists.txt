cmake_minimum_required(VERSION 2.8)

project(foundation)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
    message("No CMAKE_BUILD_TYPE specified, defaulting to ${CMAKE_BUILD_TYPE}")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")
set(CMAKE_DEBUG_POSTFIX "_d")

set(SOURCES
    stdneb.cc 
    core/debug.cc
    memory/posix/posixmemory.cc
    io/console.cc
    core/refcounted.cc
    core/rtti.cc
    core/factory.cc
    util/string.cc 
    io/posix/posixconsolehandler.cc
    io/posix/posixfswrapper.cc
    io/consolehandler.cc 
    core/coreserver.cc
    threading/posix/posixthread.cc
    core/posix/posixsysfunc.cc
    util/blob.cc 
    memory/posix/posixheap.cc
    util/posix/posixguid.cc
)

set(HEADERS
)

include(cotire)
include_directories("${PROJECT_SOURCE_DIR}")

add_library(foundation ${SOURCES})
set_target_properties(foundation PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdneb.h")
cotire(foundation)
