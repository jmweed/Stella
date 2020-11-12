#pragma once
#include <vector>
#include "SDL.h"


class GameState;

class Engine
{
public:
	void Init();
	void Goodbye();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return engine_running; }
	void Quit() { engine_running = false; }

	SDL_Window* win;
	SDL_Renderer* ren;

private:
	std::vector<GameState*> states;

	bool engine_running;
};

