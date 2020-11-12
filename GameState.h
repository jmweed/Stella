#pragma once
#include "Engine.h"

class GameState
{
public:
    virtual void Init() = 0;
    virtual void Goodbye() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(Engine* game) = 0;
    virtual void Update(Engine* game) = 0;
    virtual void Draw(Engine* game) = 0;

    void ChangeState(Engine* game, GameState* state)
    {
        game->ChangeState(state);
    };

protected: 
    GameState() { }
};
