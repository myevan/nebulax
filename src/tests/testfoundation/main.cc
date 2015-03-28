//------------------------------------------------------------------------------
//  testfoundation/main.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "foundation.h"
#include "core/coreserver.h"
#include "core/sysfunc.h"
#include "testbase/testrunner.h"
#include "stringtest.h"
#include "atomtest.h"
#include "arraytest.h"
#include "stacktest.h"
#include "listtest.h"
#include "queuetest.h"
#include "dictionarytest.h"
#include "hashtabletest.h"
#include "fixedarraytest.h"
#include "fixedtabletest.h"
#include "ringbuffertest.h"
#include "guidtest.h"
#include "proxytest.h"
#include "varianttest.h"
#include "runlengthcodectest.h"
#include "cmdlineargstest.h"
#include "threadtest.h"
#include "textreaderwritertest.h"
#include "xmlreaderwritertest.h"
#include "binaryreaderwritertest.h"
#include "messagereaderwritertest.h"
#include "memorystreamtest.h"
#include "fileservertest.h"
#include "streamservertest.h"
#include "mediatypetest.h"
#include "float4test.h"
#include "matrix44test.h"
#include "uritest.h"
#include "zipfstest.h"
#include "memorypooltest.h"

#if TODO
#include "iointerfacetest.h"
#include "attributecontainertest.h"

#include "attributetabletest.h"
#include "luaservertest.h"
#include "excelxmlreadertest.h"
#endif

using namespace Core;
using namespace Test;

int
__cdecl main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName("Nebula3 Foundation Tests");
    coreServer->Open();

    n_printf("NEBULA3 FOUNDATION TESTS\n");
    n_printf("========================\n");

    // setup and run test runner
    Ptr<TestRunner> testRunner = TestRunner::Create();
    testRunner->AttachTestCase(StringTest::Create());   
    testRunner->AttachTestCase(AtomTest::Create());
    testRunner->AttachTestCase(ArrayTest::Create());
    testRunner->AttachTestCase(StackTest::Create());
    testRunner->AttachTestCase(ListTest::Create());
    testRunner->AttachTestCase(QueueTest::Create());
    testRunner->AttachTestCase(DictionaryTest::Create());
    testRunner->AttachTestCase(HashTableTest::Create());
    testRunner->AttachTestCase(FixedArrayTest::Create());
    testRunner->AttachTestCase(FixedTableTest::Create());
    testRunner->AttachTestCase(RingBufferTest::Create());
    testRunner->AttachTestCase(GuidTest::Create());
    testRunner->AttachTestCase(ProxyTest::Create());
    testRunner->AttachTestCase(VariantTest::Create());
    testRunner->AttachTestCase(RunLengthCodecTest::Create());
    testRunner->AttachTestCase(CmdLineArgsTest::Create());
    testRunner->AttachTestCase(ThreadTest::Create());
    testRunner->AttachTestCase(TextReaderWriterTest::Create());
    testRunner->AttachTestCase(XmlReaderWriterTest::Create());
    testRunner->AttachTestCase(BinaryReaderWriterTest::Create());
    testRunner->AttachTestCase(MessageReaderWriterTest::Create());
    testRunner->AttachTestCase(MemoryStreamTest::Create());
    testRunner->AttachTestCase(FileServerTest::Create());
    testRunner->AttachTestCase(StreamServerTest::Create());
    testRunner->AttachTestCase(MediaTypeTest::Create());
    testRunner->AttachTestCase(Float4Test::Create());
    testRunner->AttachTestCase(Matrix44Test::Create());
    testRunner->AttachTestCase(URITest::Create());
    testRunner->AttachTestCase(ZipFSTest::Create());
    testRunner->AttachTestCase(MemoryPoolTest::Create());
#ifdef TODO
    testRunner->AttachTestCase(IOInterfaceTest::Create());
    testRunner->AttachTestCase(AttributeContainerTest::Create());
    testRunner->AttachTestCase(ExcelXmlReaderTest::Create());
    testRunner->AttachTestCase(LuaServerTest::Create());
    testRunner->AttachTestCase(AttributeTableTest::Create());
#endif
    testRunner->Run(); 

    coreServer->Close();
    testRunner = 0;
    coreServer = 0;
    
    Core::SysFunc::Exit(0);
    return 0;
}
