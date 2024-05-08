#include <game/card.h>
#include <game/deck.h>
#include <game/game_state.h>
#include <game/actions/play_card_action.h>
#include <game/actions/discard_card_action.h>
#include <game/actions/hint.h>
#include <game/actions/hint_action.h>

#include <algorithm>
#include <random>

Deck::Deck()
{
    std::vector<Card> cards;
    for (CardValue_t i = 1; i <= 5; i++)
    {
        
        Card red = Card(RED, i);
        Card blue = Card(BLUE, i);
        Card white = Card(WHITE, i);
        Card green = Card(GREEN, i);
        Card yellow = Card(YELLOW, i);
        for (unsigned char j = 0; j < getMaxCopies(red); j++)
        {
            cards.push_back(red); cards.push_back(blue); cards.push_back(white); cards.push_back(green); cards.push_back(yellow);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);
    
    for (const Card& card: cards)
    {
        deck.push(card);
    }
}

std::optional<Card> Deck::drawCard()
{
    if (deck.empty()) { return std::optional<Card>(); }
    const Card& card = deck.front();
    deck.pop();
    return std::optional<Card>(card);
}