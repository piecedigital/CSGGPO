#pragma once

#include <string>
#include "ggponet.h"

extern "C" {
#define EXPFNC(rtype) __declspec(dllexport) rtype __stdcall

	typedef bool (*BeginDelegate)(char* game);

	EXPFNC(int) StartSession(intptr_t& sessionRef, BeginDelegate beginCallback);
}