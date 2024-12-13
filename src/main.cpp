#include <raylib.h>

#include "game.hpp"

#ifndef RESOURCES_PATH
#define RESOURCES_PATH std::string("resources/")
#endif

#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif
static Game* game_instance;

static void UpdateDrawFrame() {
	game_instance->update();
}

constexpr int TARGET_FPS = 60;

int main() {
	InitWindow(800, 450, "raylib [core] example - basic window");
	InitAudioDevice();

	Game game{};
	game_instance = &game;

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame,TARGET_FPS,1);
#else

	SetTargetFPS(TARGET_FPS);

	while (!WindowShouldClose()) {
		UpdateDrawFrame();
	}
#endif

	CloseAudioDevice();
	CloseWindow();

	return 0;
}
