#include "Engine.h"
#include "SDL.h"
#include "GameState.h"

void Engine::Init()
{
	const int SCRN_WIDTH = 1920;
	const int SCRN_HEIGHT = 1080;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer(SCRN_WIDTH, SCRN_HEIGHT, NULL, &win, &ren);

	engine_running = true;
}

void Engine::Goodbye()
{
	SDL_DestroyRenderer(Engine::ren);
	SDL_DestroyWindow(Engine::win);
	SDL_Quit();
}

void Engine::ChangeState(GameState* state)
{

	if (!states.empty())
	{
		states.back()->Goodbye();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Init();

}

void Engine::PushState(GameState* state)
{

	if (!states.empty())
	{
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Init();

}

void Engine::PopState()
{
	if (!states.empty())
	{
		states.back()->Goodbye();
		states.pop_back();
	}

	if (!states.empty())
	{
		states.back()->Resume();
	}
}

void Engine::HandleEvents()
{
	states.back()->HandleEvents(this);
}

void Engine::Update()
{
	states.back()->Update(this);
}

void Engine::Draw()
{
	states.back()->Draw(this);
}