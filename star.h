#pragma once
#include "SDL.h"
#include <cstdio>

class star
{
public:
	int xpos;
	int ypos;
	int brightness;
	int color;
	star(int nxpos, int nypos, int nbrightness, int ncolor)
	{
		xpos = nxpos;
		ypos = nypos;
		brightness = nbrightness;
		color = ncolor;
	}

	void render(SDL_Renderer * rend)
	{
		switch (color)
		{
		case 0:
		{
			SDL_SetRenderDrawColor(rend, 220, 220, 255, 255);
			break;
		}
		case 1:
		{
			SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
			break;
		}
		case 2:
		{
			SDL_SetRenderDrawColor(rend, 255, 255, 200, 200);
			break;
		}
		case 3:
		{
			SDL_SetRenderDrawColor(rend, 255, 220, 200, 150);
			break;
		}
		case 4:
		{
			if (brightness == 5)
			{
				SDL_SetRenderDrawColor(rend, 255, 150, 150, 255);
			}
			else
			{
				SDL_SetRenderDrawColor(rend, 255, 220, 220, 255);
			}
			break;
		}
		}
		//printf("Rendered a brightness %i star \n", brightness);
		switch (brightness)
		{
		case 1: 
		{
			SDL_RenderDrawPoint(rend, xpos, ypos); 
			break; 
		}
		case 2:
		{
			SDL_RenderDrawPoint(rend, xpos, ypos);
			SDL_RenderDrawPoint(rend, xpos+1, ypos);
			SDL_RenderDrawPoint(rend, xpos-1, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos+1);
			SDL_RenderDrawPoint(rend, xpos, ypos-1);
			break;
		}
		case 3:
		{
			SDL_RenderDrawPoint(rend, xpos, ypos);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos, ypos - 1);
			break;
		}
		case 4:
		{
			SDL_RenderDrawPoint(rend, xpos, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos + 2, ypos);
			SDL_RenderDrawPoint(rend, xpos - 2, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos + 2);
			SDL_RenderDrawPoint(rend, xpos, ypos - 2);
			break;
		}
		case 5:
		{
			SDL_RenderDrawPoint(rend, xpos, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos);
			SDL_RenderDrawPoint(rend, xpos + 1, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos + 1);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos);
			SDL_RenderDrawPoint(rend, xpos - 1, ypos - 1);
			SDL_RenderDrawPoint(rend, xpos + 2, ypos);
			SDL_RenderDrawPoint(rend, xpos - 2, ypos);
			SDL_RenderDrawPoint(rend, xpos, ypos + 2);
			SDL_RenderDrawPoint(rend, xpos, ypos - 2);
			break;
		}
		}

	}

};

