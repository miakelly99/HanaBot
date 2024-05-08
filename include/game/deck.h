#include "card.h"
#include <queue>
#include <optional>

#ifndef DECK_H_
#define DECK_H_

typedef unsigned char CardNum_t;

class Deck {
    const static inline std::array<CardNum_t, 5> MAX_CARD_NUMS = {3, 2, 2, 2, 1};
    public:
        Deck();
        
        std::optional<Card> drawCard();

        CardNum_t getRemainingCardNum() { return deck.size(); }

        static CardNum_t getMaxCopies(const Card& card) { return MAX_CARD_NUMS[card.getValue() - 1]; }
    private:
        std::queue<Card> deck;
};

#endif