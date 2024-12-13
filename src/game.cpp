#include "game.hpp"

#include <raylib.h>

void Game::start() {
	
}

void Game::update() {
	BeginDrawing();
	ClearBackground(RED);
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	EndDrawing();
}

Game::Game() {
}
