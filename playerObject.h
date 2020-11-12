#pragma once
#include "SDL.h"
class playerObject
{
public:
	bool visible;
	int xpos;
	int ypos;
	int tarI;

	virtual void render(SDL_Renderer * rend)
	{
		if (visible)
		{
			//printf("rendering my boy!\n");
		}
		return;
	}
};

