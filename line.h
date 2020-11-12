#pragma once
#include "playerObject.h"
class line :
    public playerObject
{
public:

    line(int nxpos, int nypos, int ntari, int ndxpos, int ndypos, int ndtari)
    {
        xpos = nxpos;
        ypos = nypos;
        tarI = ntari;
        destxpos = ndxpos;
        destypos = ndypos;
        dTarI = ndtari;
    }

    void render(SDL_Renderer* rend)
    {
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderDrawLine(rend, xpos, ypos, destxpos, destypos);
    }
    void setTarget(int ndxpos, int ndypos)
    {
        destxpos = ndxpos; 
        destypos = ndypos;
    }

private:
    int dTarI;
    int destxpos;
    int destypos;
};

