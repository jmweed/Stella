#pragma once
#include "star.h"
#include "SDL.h"
#include <time.h>
#include <array>
#include <cmath>
class galaxy
{
public:

	void generateStellae(int screenw, int screenh)
	{
		srand(time(NULL));
		for (int i = 0; i < Stellae.size(); ++i)
		{
			star * ns;
			int nxpos = rand() % screenw;
			int nypos = rand() % screenh;
			int brightnessFactor = rand() % 50 + 1;
			int color = rand() % 5;
			int nbrightness;
			if (brightnessFactor == 50)
			{
				nbrightness = 5;
			}
			else if (brightnessFactor >= 45)
			{
				nbrightness = 4;
			}
			else if (brightnessFactor >= 37)
			{
				nbrightness = 3;
			}
			else if (brightnessFactor >= 25)
			{
				nbrightness = 2;
			}
			else
			{
				nbrightness = 1;
			}
			ns = new star(nxpos, nypos, nbrightness, color);

			Stellae[i] = ns;
			printf("[GALAXY GENERATION] Generated star %i at (%i,%i) with brightness %i \n", i, nxpos, nypos, nbrightness);
		}
	}

	void renderGalaxy(SDL_Renderer* rend)
	{
		for (int i = 0; i < Stellae.size(); ++i)
		{
			Stellae[i]->render(rend);
		}
	}

	int findNearestStar(int x, int y)
	{
		int dx = 0;
		int dy = 0;
		int minD = 10000;
		int minI = -1;

		for (int i = 0; i < Stellae.size(); ++i)
		{
			dx = abs(Stellae[i]->xpos - x);
			dy = abs(Stellae[i]->ypos - y);
			if (dx + dy < minD) 
			{ 
				minD = dx + dy; 
				minI = i;
			}
		}
		return minI;
	}

	int findSecondNearestStar(int x, int y, int iavoid)
	{
		int dx = 0;
		int dy = 0;
		int minD = 10000;
		int minI = -1;

		for (int i = 0; i < Stellae.size(); ++i)
		{
			if (!(i == iavoid))
			{
				dx = abs(Stellae[i]->xpos - x);
				dy = abs(Stellae[i]->ypos - y);
				if (dx + dy < minD)
				{
					minD = dx + dy;
					minI = i;
				}
			}
		}
		return minI;
	}

	std::array<star*, 1000> Stellae;
};

