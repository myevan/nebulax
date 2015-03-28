cmake_minimum_required(VERSION 2.8)

project(NebulaXFoundation)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")

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
    util/posix/posixguid.cc)

include(cotire)
include(xplatform)
include_directories("${PROJECT_SOURCE_DIR}")

add_library(NebulaXFoundation ${SOURCES})
set_target_properties(NebulaXFoundation PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdneb.h")
cotire(NebulaXFoundation)
