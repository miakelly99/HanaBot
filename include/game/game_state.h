#include "player.h"
#include "deck.h"
#include "card.h"
#include "card_info.h"

#ifndef GAME_STATE_H_
#define GAME_STATE_H_

typedef std::vector<Card> DiscardPile_t;
typedef std::array<CardValue_t, 5> CardStacks_t;
typedef unsigned short TurnNum_t;
typedef unsigned char PlayerNum_t;
typedef unsigned char Counter_t;

class GameState
{
public:
    friend class PlayCardAction;
    friend class DiscardCardAction;
    friend class HintAction;

    GameState(): discard_pile(), deck(), players({Player(), Player(), Player()}), stacks({0, 0, 0, 0, 0}), turn_number(0), countdown_turns(3), strikes(0), hints(8) {}
    GameState(const GameState& other)
    {
        this->copy(other);
    }

    const GameState& operator=(const GameState& other)
    {
        if (this == &other) return *this;
        this->copy(other);
        return *this;
    }

    static GameState init()
    {
        GameState game_state;
        for (PlayerNum_t player = 0; player < 3; player++)
        {
            for (CardNum_t i = 0; i < 5; i++)
            {
                game_state.players[i].setCard(game_state.deck.drawCard(), i);
            }
        }
        return game_state;
    }

private:
    DiscardPile_t discard_pile;
    Deck deck;
    std::array<Player, 3> players;
    CardStacks_t stacks;
    TurnNum_t turn_number;
    TurnNum_t countdown_turns;
    Counter_t strikes;
    Counter_t hints;
    

    void copy (const GameState& other)
    {
        this->discard_pile = other.discard_pile;
        this->deck = other.deck;
        this->players = other.players;
        this->stacks = other.stacks;
        this->turn_number = other.turn_number;
        this->countdown_turns = other.countdown_turns;
        this->strikes = other.strikes;
    }
};

#endif