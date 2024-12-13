#pragma once

class Game {
	public:
		Game();
		Game(Game& other) = delete;
		void operator=(const Game&) = delete;

		void start();
		void update();
};
