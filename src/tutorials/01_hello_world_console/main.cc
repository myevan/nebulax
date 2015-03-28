#include "stdneb.h"

#include <core/coreserver.h>
#include <core/sysfunc.h>

using namespace Core;

int main()
{
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName("HelloWorldConsole");
    coreServer->Open();

    n_printf("Hello, World\n");

    coreServer->Close();
    coreServer = NULL;

    SysFunc::Exit(0);
    return 0;
}
