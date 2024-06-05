#include "log.h"

namespace Log
{

	void Log(const char* format, ...)
	{
		char buf[1024] = { 0 };

		va_list args;
		va_start(args, format);
		vsprintf(buf, format, args);

		OutputDebugStringA(buf);

		va_end(args);
	}

	void LogHexDump(unsigned char* ptr, int len)
	{
		char buf[8192] = { 0 };
		char tmp[16] = { 0 };

		int bufPos = 0;

		for (int i = 0; i < len; i++)
		{
			auto value = ptr[i];

			memset(tmp, 0, 16);
			sprintf(tmp, "%02X ", value);
			strcat(buf, tmp);
		}

		Log("[HexDump] %s", buf);
	}

}