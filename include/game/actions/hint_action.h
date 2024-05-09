#include <iostream>
#include "hint.h"

#ifndef HINT_ACTION_H_
#define HINT_ACTION_H_

class HintAction: public AbstractAction
{
public:
    HintAction(PlayerNum_t player_index, Hint* hint): player_index(player_index), hint(hint) {}

    void modifyGameState(GameState& game_state) const override
    {
        if (game_state.hints == 0)
        {
            std::cerr << "Error: attempting to hint with none available" << std::endl;
            exit(1);
        }
        game_state.hints--;
        Player* player = &game_state.players[player_index];
        for (CardNum_t i = 0; i < 5; i++)
        {
            if (player->getHand()[i].has_value())
            {
                CardInfo new_info = hint->getInfoProvidedToCard(player->getHand()[i].value());
                CardInfo old_info = player->getHandInfo()[i].value();
                player->setHandInfo(std::optional<CardInfo>(new_info + old_info), i);
            }
        }

    }
    
private:
    PlayerNum_t player_index;
    Hint* hint;
};

#endif