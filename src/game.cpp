#include "game.hpp"

#include <raylib.h>

Game* Game::instance{nullptr};
std::mutex Game::mutex;


Game* Game::get_instance() {
	std::lock_guard lock(mutex);
	if (instance == nullptr) {
		instance = new Game();
	}

	return instance;
}

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
