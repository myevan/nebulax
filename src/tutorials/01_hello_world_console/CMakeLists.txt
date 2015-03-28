cmake_minimum_required(VERSION 2.8)

project(HelloWorldConsole)

if(NOT CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake")
endif()

set(SOURCES
    stdneb.cc 
    main.cc)

include(cotire)
include(xplatform)

include_directories("${PROJECT_SOURCE_DIR}/../../foundation")
link_directories("${PROJECT_SOURCE_DIR}/../../foundation/${BUILD_DIR}")

add_executable(HelloWorldConsole ${SOURCES})
target_link_libraries(HelloWorldConsole NebulaXFoundation${CMAKE_DEBUG_POSTFIX})
set_target_properties(HelloWorldConsole PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "stdneb.h")
cotire(HelloWorldConsole)
