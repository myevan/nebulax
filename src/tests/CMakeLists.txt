include_directories("${NebulaX_SOURCE_DIR}/tests")

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
    testfoundation/runlengthcodectest.cc
    testfoundation/cmdlineargstest.cc
    testfoundation/threadtest.cc
    testfoundation/textreaderwritertest.cc
    testfoundation/binaryreaderwritertest.cc
    testfoundation/memorystreamtest.cc
    #testfoundation/memorypooltest.cc
    #testfoundation/uritest.cc
    #testfoundation/float4test.cc
    #testfoundation/matrix44test.cc
    #testfoundation/attributecontainertest.cc
    #testfoundation/attributetabletest.cc

    #testfoundation/excelxmlreadertest.cc
    #testfoundation/fileservertest.cc
    #testfoundation/iointerfacetest.cc
    #testfoundation/luaservertest.cc
    #testfoundation/mediatypetest.cc
    #testfoundation/messagereaderwritertest.cc
    #testfoundation/simpletreetest.cc
    #testfoundation/streamservertest.cc
    #testfoundation/testattrs.cc
    #testfoundation/xmlreaderwritertest.cc
    #testfoundation/zipfstest.cc
)

target_link_libraries(NebulaXTestFoundation NebulaXFoundation NebulaXTestBase ${SYSTEM_LIBS})
