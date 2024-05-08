#include "game/game_state.h"

#ifndef ABSTRACT_ACTION_H_
#define ABSTRACT_ACTION_H_

class AbstractAction
{
    virtual void modifyGameState(GameState& game_state);
};

#endif