#pragma once
#include <mutex>

class Game {

	private:
		static Game* instance;
		static std::mutex mutex;

	public:
		Game(Game& other) = delete;
		void operator=(const Game&) = delete;
	
		static Game* get_instance();

		void start();
		void update();

	protected:
		Game();
};
