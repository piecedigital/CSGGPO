#pragma once

#include <string>
#include "ggponet.h"

extern "C" {
#define EXPFNC(rtype) __declspec(dllexport) rtype __stdcall

	typedef bool (*BeginGameDelegate)(char* game);
	typedef bool (*SaveGameStateDelegate)(char* game);
	typedef bool (*LoadGameStateDelegate)(char* game);
	typedef bool (*LogGameStateDelegate)(char* game);
	typedef bool (*FreeBufferDelegate)(char* game);
	typedef bool (*AdvanceFrameDelegate)(char* game);
	typedef bool (*OnEventDelegate)(char* game);

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