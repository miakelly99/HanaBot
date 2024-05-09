#include "game/game_state.h"

#ifndef ABSTRACT_ACTION_H_
#define ABSTRACT_ACTION_H_

class AbstractAction
{
public:
    AbstractAction() {}
    AbstractAction(AbstractAction&& o) {}

    virtual void modifyGameState(GameState& game_state) const = 0;
};

#endif