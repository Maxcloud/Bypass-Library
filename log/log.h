#pragma once

#include <stdio.h>
#include <string>
#include <windows.h>

namespace Log
{
	void Log(const char* fml, ...);
	void LogHexDump(unsigned char* ptr, int len);
}