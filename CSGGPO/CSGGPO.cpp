#include "pch.h"

#include "CSGGPO.h"

using namespace CSGGPO;

int GGPO:: Test(intptr_t &sessionRef)
{
	GGPOSession* session;
	GGPOSessionCallbacks callbacks;
	// callbacks.begin_game
	char* game = "test_game";
	int player_count = 2;
	int input_size = sizeof(int);
	int localpost = 9970;

	int response = ggpo_start_session(&session, &callbacks, game, player_count, input_size, localpost);
	sessionRef = (intptr_t)session;
	return response;
}
