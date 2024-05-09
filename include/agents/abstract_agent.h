#ifndef ABSTRACT_AGENT_H_
#define ABSTRACT_AGENT_H_

#include "game/game_state.h"
#include "game/actions/abstract_action.h"

class AbstractAgent
{
public:
    AbstractAgent() {}
    AbstractAgent(AbstractAgent&& o) {}

    virtual AbstractAction* getActionForGameState(const GameState& game_state) const = 0;
};

#endif