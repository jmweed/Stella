#pragma once
#include "playerObject.h"
class selectionArrow :
    public playerObject
{
public:
    bool directionLeft = true;

    selectionArrow(int nxpos, int nypos, int ntari)
    {
        xpos = nxpos;
        ypos = nypos;
        tarI = ntari;
        visible = true;
        if (xpos >= 1500)
        {
            directionLeft = false;
        }
    }

    void render(SDL_Renderer* rend)
    {
        if (visible)
        {
            SDL_SetRenderDrawColor(rend, 0, 255, 128, 255);
            SDL_RenderDrawLine(rend, xpos+1, ypos, xpos + 9, ypos);
            SDL_RenderDrawLine(rend, xpos+1, ypos, xpos + 4, ypos + 3);
            SDL_RenderDrawLine(rend, xpos+1, ypos, xpos + 4, ypos - 3);
        }
    }
};

