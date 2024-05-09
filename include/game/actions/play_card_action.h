#include "abstract_action.h"

#include <iostream>

#ifndef PLAY_CARD_ACTION_H_
#define PLAY_CARD_ACTION_H_

class PlayCardAction: public AbstractAction
{
public:
    PlayCardAction(PlayerNum_t player, CardNum_t index): player(player), index(index) {}

    void modifyGameState(GameState& game_state) const override
    {
        CardOpt_t card_opt = game_state.players[player].getHand()[index];
        if (!card_opt.has_value())
        {
            std::cerr << "Error: attempting to play card that does not exist" << std::endl;
            exit(1);
        }
        Card card = card_opt.value();
        CardStacks_t stacks = game_state.stacks;
        CardValue_t stack_value = stacks[card.getColor()];

        if (stack_value + 1 == card.getValue())
        {
            if (card.getValue() == 5) { game_state.hints++; }
            game_state.stacks[card.getColor()]++;
        }
        else 
        {
            game_state.strikes++;
            game_state.discard_pile.push_back(card);
        }
        game_state.players[player].setCard(std::optional<Card>(), index);
    }
    
private:
    PlayerNum_t player;
    CardNum_t index;
};

#endif