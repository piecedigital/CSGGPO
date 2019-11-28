#pragma once

#include <string>
#include "bin/ggponet.h"

extern "C" {
#define EXPFNC(rtype) __declspec(dllexport) rtype __stdcall

	typedef bool (*BeginGameDelegate)(char* game);
	typedef bool (*SaveGameStateDelegate)(unsigned char** buffer, int* len, int* checksum, int frame);
	typedef bool (*LoadGameStateDelegate)(unsigned char* buffer, int len);
	typedef bool (*LogGameStateDelegate)(char* filename, unsigned char* buffer, int len);
	typedef void (*FreeBufferDelegate)(void* buffer);
	typedef bool (*AdvanceFrameDelegate)(int flags);
	typedef bool (*OnEventDelegate)(GGPOEvent* info);

	EXPFNC(int) CGStartSession(
		intptr_t& sessionRef,
		BeginGameDelegate beginGameCallback,
		SaveGameStateDelegate saveGameStateCallback,
		LoadGameStateDelegate loadGameStateCallback,
		LogGameStateDelegate logGameStateCallback,
		FreeBufferDelegate freeBufferCallback,
		AdvanceFrameDelegate advanceFrameCallback,
		OnEventDelegate onEventCallback
	);
}