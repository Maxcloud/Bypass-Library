#pragma once

#ifndef KILLSWITCH
#define KILLSWITCH
#endif

// #ifndef PRINT_DEBUG_INFO
// #define PRINT_DEBUG_INFO
// #endif

#ifdef UNICODE
#undef UNICODE
#endif

#ifdef _UNICODE
#undef _UNICODE
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _STL_SECURE_NO_WARNINGS
#define _STL_SECURE_NO_WARNINGS
#endif

#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

#include <WinSock2.h>
#include <Windows.h>
#include <Winternl.h>

#include <detours.h>
#pragma comment(lib, "detours")

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "log/log.h"

#ifndef Padding
#define Padding(x) struct { unsigned char __padding##x[(x)]; };
#endif

namespace function
{
	bool close_handle(std::string const& handle_name);
	bool redirect(bool enable, void** function, void* redirection);
}