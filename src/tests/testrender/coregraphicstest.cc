//------------------------------------------------------------------------------
//  coregraphicstest.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphicstest.h"
#include "io/filestream.h"
#include "resources/simpleresourcemapper.h"
#include "coregraphics/streamtextureloader.h"
#include "coregraphics/streammeshloader.h"
#include "coreanimation/streamanimationloader.h"
#include "resources/managedtexture.h"
#include "resources/managedmesh.h"
#include "coreanimation/managedanimresource.h"

namespace Test
{
__ImplementClass(Test::CoreGraphicsTest, 'cgtt', Test::TestCase);

using namespace Util;
using namespace CoreGraphics;
using namespace CoreAnimation;
using namespace IO;
using namespace Interface;
using namespace Resources;
using namespace Debug;
using namespace Http;

//------------------------------------------------------------------------------
/**
*/
bool
CoreGraphicsTest::SetupRuntime()
{
    // setup foundation layer runtime
    this->ioServer = IoServer::Create();
    this->ioServer->RegisterStandardUriSchemes();
    this->ioServer->SetupStandardAssigns();

    // setup asynchronous IO
    this->ioInterface = IOInterface::Create();
    this->ioInterface->Open();
    if (IoServer::Instance()->FileExists("home:export.zip"))
    {
        // main thread
        this->ioServer->MountZipArchive("home:export.zip");

        // io thread
        Ptr<Interface::MountZipArchive> mountZipArchiveMsg = Interface::MountZipArchive::Create();
        mountZipArchiveMsg->SetURI("home:export.zip");
        this->ioInterface->Send(mountZipArchiveMsg.upcast<Messaging::Message>());
    }

    // setup HTTP subsystem
    this->httpInterface = Http::HttpInterface::Create();
    this->httpInterface->Open();

    // setup Debug subsystem
    this->debugInterface = DebugInterface::Create();
    this->debugInterface->Open();
    
    // setup the display device
    this->displayDevice = DisplayDevice::Create();
    this->displayDevice->SetFullscreen(false);
    this->displayDevice->SetDisplayMode(DisplayMode(0, 0, 64, 64, PixelFormat::X8R8G8B8));
    this->displayDevice->SetWindowTitle("Nebula3 Test Window");
    if (this->displayDevice->Open())
    {
        this->renderDevice = RenderDevice::Create();
        if (!this->renderDevice->Open())
        {
            this->displayDevice->Close();
            this->renderDevice = 0;
            this->displayDevice = 0;
            return false;
        }
    }

    // create vertex layout server
    this->vertexLayoutServer = VertexLayoutServer::Create();
    this->vertexLayoutServer->Open();

    // setup the shader server
    this->shaderServer = ShaderServer::Create();
    if (!this->shaderServer->Open())
    {
        return false;
    }

    // setup the resource server
    this->resServer = SharedResourceServer::Create();
    if (!this->resServer->Open())
    {
        return false;
    }

    // setup the resource manager
    this->resManager = ResourceManager::Create();
    this->resManager->Open();

    Ptr<SimpleResourceMapper> texMapper = SimpleResourceMapper::Create();
    texMapper->SetPlaceholderResourceId(ResourceId("tex:system/placeholder.dds"));
    texMapper->SetResourceClass(Texture::RTTI);
    texMapper->SetResourceLoaderClass(StreamTextureLoader::RTTI);
    texMapper->SetManagedResourceClass(ManagedTexture::RTTI);
    this->resManager->AttachMapper(texMapper.upcast<ResourceMapper>());

    Ptr<SimpleResourceMapper> meshMapper = SimpleResourceMapper::Create();
    meshMapper->SetPlaceholderResourceId(ResourceId("msh:system/placeholder_s_0.nvx2"));
    meshMapper->SetResourceClass(Mesh::RTTI);
    meshMapper->SetResourceLoaderClass(StreamMeshLoader::RTTI);
    meshMapper->SetManagedResourceClass(ManagedMesh::RTTI);
    this->resManager->AttachMapper(meshMapper.upcast<ResourceMapper>());

    Ptr<SimpleResourceMapper> animMapper = SimpleResourceMapper::Create();
    animMapper->SetPlaceholderResourceId(ResourceId("anim:characters/mensch_m_variations.nax2"));
    animMapper->SetResourceClass(AnimResource::RTTI);
    animMapper->SetResourceLoaderClass(StreamAnimationLoader::RTTI);
    animMapper->SetManagedResourceClass(ManagedAnimResource::RTTI);
    this->resManager->AttachMapper(animMapper.upcast<ResourceMapper>());

    return true;
}

//------------------------------------------------------------------------------
/**
*/
void
CoreGraphicsTest::ShutdownRuntime()
{
    this->resManager->Close();
    this->resManager = 0;

    this->resServer->Close();
    this->resServer = 0;

    this->shaderServer->Close();
    this->shaderServer = 0;

    this->vertexLayoutServer->Close();
    this->vertexLayoutServer = 0;

    this->renderDevice->Close();
    this->renderDevice = 0;

    this->displayDevice->Close();
    this->displayDevice = 0;

    this->debugInterface->Close();
    this->debugInterface = 0;

    this->httpInterface->Close();
    this->httpInterface = 0;

    this->ioInterface->Close();
    this->ioInterface = 0;

    this->ioServer = 0;
}

}