#pragma once
//------------------------------------------------------------------------------
/**
    @file core/win32/precompiled.h
    
    Contains precompiled headers on the Win32 platform.
    
    (C) 2007 Radon Labs GmbH
*/
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define _WIN32_WINNT 0x500

#define NOGDICAPMASKS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCTLMGR
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSERVICE
#define NOSOUND
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

// Windows headers
#include <windows.h>
#include <process.h>
#include <shfolder.h>
#include <windows.h>
#include <strsafe.h>
#include <wininet.h>
#include <winsock2.h>
#include <rpc.h>
#include <dbghelp.h>
#include <intrin.h>

// crt headers
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <algorithm>

// DirectX headers
#if _DEBUG
#define D3D_DEBUG_INFO (1)
#endif

#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr9.h>
#include <xinput.h>
#include <xact3.h>
#include <xact3d3.h>
//------------------------------------------------------------------------------


