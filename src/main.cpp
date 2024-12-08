#include <iostream>
#include <filesystem>

#include "raylib.h"

#ifndef RESOURCES_PATH
#define RESOURCES_PATH std::string("resources/")
#endif

#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

static void UpdateDrawFrame() {
	BeginDrawing();
	ClearBackground(RED);
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}

constexpr int TARGET_FPS = 60;


int main() {
	
	InitWindow(800, 450, "raylib [core] example - basic window");
	InitAudioDevice();


#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame,TARGET_FPS,1);
#else

	SetTargetFPS(TARGET_FPS);
	
	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}
#endif

	CloseAudioDevice();
	CloseWindow();

	return 0;
}