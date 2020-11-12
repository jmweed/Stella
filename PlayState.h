#pragma once
#include "gamestate.h"
#include "SDL.h"
#include "galaxy.h"
#include "overlay.h"
#include "selectionArrow.h"
#include "line.h"
#include "constellation.h"

class PlayState : public GameState
{
public:
    void Init();
    void Goodbye();

    void Pause();
    void Resume();

    void HandleEvents(Engine * game);
    void Update(Engine * game);
    void Draw(Engine * game);

    void ChangeState(Engine * game, GameState * state)
    {
        game->ChangeState(state);
    };

    static PlayState* Instance() {
        return &playstate_t;
    }

protected:
    PlayState() { }

private:
    galaxy MilkyWay;
    overlay MWOverlay;
    static PlayState playstate_t;
    bool needsBackground = true;
    bool click = false;
    constellation freeConstellation;
};