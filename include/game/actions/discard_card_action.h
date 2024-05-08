#include "abstract_action.h"

#include <iostream>

#ifndef DISCARD_CARD_ACTION_H
#define DISCARD_CARD_ACTION_H

class DiscardCardAction: AbstractAction
{
public:
    DiscardCardAction(PlayerNum_t player, CardNum_t index): player(player), index(index) {}

    void modifyGameState(GameState& game_state) override
    {
        CardOpt_t card_opt = game_state.players[player].getHand()[index];
        if (!card_opt.has_value())
        {
            std::cerr << "Error: attempting to discard card that does not exist" << std::endl;
            exit(1);
        }
        Card card = card_opt.value();

        game_state.discard_pile.push_back(card);
        game_state.players[player].setCard(std::optional<Card>(), index);
        game_state.hints++;
    }
    
private:
    PlayerNum_t player;
    CardNum_t index;
};

#endif