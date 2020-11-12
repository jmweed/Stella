#include "Engine.h"
#include "PlayState.h"
#undef main;

int main(int argc, char* argv[])
{
	Engine game;

	game.Init();

	game.ChangeState(PlayState::Instance());

	while ( game.Running() )
	{
		game.HandleEvents();
		//game.Draw();
	}

	game.Goodbye();

	return 0;
}