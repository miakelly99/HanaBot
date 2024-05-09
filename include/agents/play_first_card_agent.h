#ifndef PLAY_FIRST_CARD_AGENT_H_
#define PLAY_FIRST_CARD_AGENT_H_

#include "abstract_agent.h"
#include "game/actions/play_card_action.h"

class PlayFirstCardAgent: public AbstractAgent
{
public:
    AbstractAction* getActionForGameState(const GameState& game_state) const override
    {
        PlayCardAction* action = new PlayCardAction(game_state.getCurrentPlayer(), 0);
        return (AbstractAction*) action;
    }
};

#endif