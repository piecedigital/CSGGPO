#include "pch.h"

#include "CSGGPO.h"

EXPFNC(int) StartSession(intptr_t &sessionRef, BeginDelegate beginCallback)
{
	GGPOSession* session;
	GGPOSessionCallbacks callbacks;
	callbacks.begin_game = beginCallback;
	char* game = "test_game";
	int player_count = 2;
	int input_size = sizeof(int);
	int localpost = 9970;

	int response = ggpo_start_session(&session, &callbacks, game, player_count, input_size, localpost);
	sessionRef = (intptr_t)session;
	return response;
}
