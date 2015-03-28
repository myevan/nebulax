cmake_minimum_required(VERSION 2.8)

project(HelloWorldTests)

if(NOT CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")
endif()

include(xplatform)
include(nebulax)

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
    testfoundation/stringtest.cc
    testfoundation/atomtest.cc
    testfoundation/arraytest.cc
    testfoundation/stacktest.cc
    testfoundation/listtest.cc
    testfoundation/queuetest.cc
    testfoundation/dictionarytest.cc
    testfoundation/hashtabletest.cc
    testfoundation/fixedarraytest.cc
    testfoundation/fixedtabletest.cc
    testfoundation/ringbuffertest.cc
    testfoundation/guidtest.cc
    testfoundation/proxytest.cc
    testfoundation/varianttest.cc
    #testfoundation/runlengthcodectest.cc
    #testfoundation/uritest.cc
    #testfoundation/float4test.cc
    #testfoundation/matrix44test.cc
    #testfoundation/cmdlineargstest.cc
    #testfoundation/attributecontainertest.cc
    #testfoundation/attributetabletest.cc

    #testfoundation/binaryreaderwritertest.cc
    #testfoundation/excelxmlreadertest.cc
    #testfoundation/fileservertest.cc
    #testfoundation/iointerfacetest.cc
    #testfoundation/luaservertest.cc
    #testfoundation/mediatypetest.cc
    #testfoundation/memorypooltest.cc
    #testfoundation/memorystreamtest.cc
    #testfoundation/messagereaderwritertest.cc
    #testfoundation/simpletreetest.cc
    #testfoundation/streamservertest.cc
    #testfoundation/testattrs.cc
    #testfoundation/textreaderwritertest.cc
    #testfoundation/threadtest.cc
    #testfoundation/xmlreaderwritertest.cc
    #testfoundation/zipfstest.cc
)

target_link_libraries(NebulaXTestFoundation 
    NebulaXFoundation${CMAKE_DEBUG_POSTFIX} 
    NebulaXTestBase${CMAKE_DEBUG_POSTFIX})
