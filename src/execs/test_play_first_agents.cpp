#include "agents/play_first_card_agent.h"
#include "game/game_runner.h"

#include <iostream>
#include <iomanip>

const unsigned long NUM_TESTS = 100000;

int main()
{
    PlayFirstCardAgent agent;
    std::array<AbstractAgent*, 3> behaviors = {&agent, &agent, &agent};
    unsigned long wins = 0;
    unsigned long total_score = 0;
    for (unsigned long i = 0; i < NUM_TESTS; i++)
    {
        GameState final_state = GameRunner::runGame(behaviors);

        Score_t game_score = final_state.getScore();
        total_score += game_score;
        if (game_score == 25)
        {
            wins++;
        }
    }

    std::cout << "Total wins: " << wins << " out of " << NUM_TESTS << " games (" <<  std::setprecision(2) << ((float) wins / NUM_TESTS * 100) << "%)" << std::endl;
    std::cout << "Average score: " << std::setprecision(2) << ((double) total_score / NUM_TESTS) << "\n";
}