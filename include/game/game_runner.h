#include "game_state.h"
#include "agents/abstract_agent.h"

#ifndef GAME_RUNNER_H_
#define GAME_RUNNER_H_

typedef std::array<AbstractAgent*, 3> AgentBehavior_t;

class GameRunner
{
public:
    static GameState runGame(const AgentBehavior_t& agent_behaviors);
};

#endif