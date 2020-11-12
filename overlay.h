#pragma once
#include <deque>
#include "playerObject.h"
#include "SDL.h"

class overlay
{
public:
	std::deque<playerObject*> freeObjects;


	void render(SDL_Renderer * rend) 
	{
		for (int i = 0; i < freeObjects.size(); ++i)
		{
			freeObjects[i]->render(rend);
		}
	}
	void reset()
	{
		freeObjects.clear();
	}

	bool testIfSelection(int x, int y)
	{
		if (getSelectionX() == x && getSelectionY() == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getSelectionX()
	{
		return freeObjects.front()->xpos;
	}
	int getSelectionY()
	{
		return freeObjects.front()->ypos;
	}
	int getSelectionI()
	{
		return freeObjects.front()->tarI;
	}
};

