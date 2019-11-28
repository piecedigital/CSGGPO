#include "pch.h"

#include "CSGGPO.h"
typedef struct {
	char* foo;
	char* betty;
	char* foobar;
	bool itIs;
} GameState;
EXPFNC(int) CGStartSession(
	intptr_t &sessionRef,
	BeginGameDelegate beginGameCallback,
	SaveGameStateDelegate saveGameStateCallback,
	LoadGameStateDelegate loadGameStateCallback,
	LogGameStateDelegate logGameStateCallback,
	FreeBufferDelegate freeBufferCallback,
	AdvanceFrameDelegate advanceFrameCallback,
	OnEventDelegate onEventCallback
)
{
	GGPOSession* session;
	GGPOSessionCallbacks callbacks;
	callbacks.begin_game = beginGameCallback;
	callbacks.save_game_state = saveGameStateCallback;
	callbacks.load_game_state = loadGameStateCallback;
	callbacks.log_game_state = logGameStateCallback;
	callbacks.free_buffer = freeBufferCallback;
	callbacks.advance_frame = advanceFrameCallback;
	callbacks.on_event = onEventCallback;
	char* game = "test_game";
	int player_count = 2;
	int input_size = sizeof(int);
	int localpost = 9970;

	beginGameCallback("test_game");

	GameState gs;
	gs.foo = "bar";
	gs.betty = "boop";
	gs.foobar = "bettyboop";
	gs.itIs = false;
	int len = sizeof(gs);
	unsigned char *buffer = (unsigned char *)malloc(len);
	memcpy(&buffer, &gs, len);
	int checksum = 0;
	int frame = 0;
	saveGameStateCallback(&buffer, &len, &checksum, frame);
	// loadGameStateCallback(unsigned char* buffer, int len);
	// logGameStateCallback(char* filename, unsigned char* buffer, int len);
	// freeBufferCallback(void* buffer);
	// advanceFrameCallback(int flags);
	// onEventCallback(GGPOEvent * info);

	int response = 1;// ggpo_start_session(&session, &callbacks, game, player_count, input_size, localpost);
	// sessionRef = (intptr_t)session;
	return response;
}
