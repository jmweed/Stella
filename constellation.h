#pragma once
#include "line.h"
#include "SDL.h"
#include <vector>
class constellation
{
public:
	void deleteLastLine()
	{
		if (Lines.size() > 0)
		{
			Lines.pop_back();
		}
	}

	void addLine(playerObject* NL)
	{
		Lines.push_back(NL);
	}

	void render(SDL_Renderer* rend)
	{
		for (int i = 0; i < Lines.size(); ++i)
		{
			Lines[i]->render(rend);
		}
	}
	std::vector<playerObject*> Lines;

	void reset()
	{
		Lines.clear();
	}
};

