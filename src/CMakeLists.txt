cmake_minimum_required(VERSION 3.0.2)

project(NebulaX)

option(N_BUILD_TESTS "Build Tests" ON)
option(N_BUILD_TUTORIALS "Build Tutorials" ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-inline-new-delete -Wno-deprecated-declarations") 

include(cotire)
include(xplatform)

include_directories("${CMAKE_SOURCE_DIR}/foundation")

include_directories("${XPLATFORM_DIR}/zlib-1.2.8/include")
link_directories("${XPLATFORM_DIR}/zlib-1.2.8/lib/static")

include_directories("${XPLATFORM_DIR}/tinyxml-2.6.2/include")
link_directories("${XPLATFORM_DIR}/tinyxml-2.6.2/lib/static")

add_subdirectory(foundation)

if(N_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(N_BUILD_TUTORIALS)
    add_subdirectory(tutorials)
endif()
