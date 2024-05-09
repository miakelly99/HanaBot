#include "game/game_runner.h"
#include "game/game_state.h"

#include <iostream>

GameState GameRunner::runGame(const AgentBehavior_t& agent_behaviors)
{
    GameState current_state = GameState::init();
    while(!current_state.isEndState())
    {
        AbstractAgent* current_agent = agent_behaviors[current_state.getCurrentPlayer()];
        AbstractAction* next_action = current_agent->getActionForGameState(current_state);
        next_action->modifyGameState(current_state);
        current_state.iterateState();
    }
    return current_state;
}