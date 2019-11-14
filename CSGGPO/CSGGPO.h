#pragma once

#include <string>
#include "ggponet.h"

extern "C" {
	typedef bool (*BeginDelegate)(char* game);

	__declspec(dllexport) int __stdcall Test(intptr_t& sessionRef, BeginDelegate beginCallback);
}