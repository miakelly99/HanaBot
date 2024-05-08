#include "card.h"
#include "card_info.h"

#include <optional>

#ifndef PLAYER_H_
#define PLAYER_H_

typedef std::optional<Card> CardOpt_t;
typedef std::array<CardOpt_t, 5> Hand_t;

typedef std::optional<CardInfo> CardInfoOpt_t;
typedef std::array<CardInfoOpt_t, 5> HandInfo_t;

class Player
{
public:
    Player(): hand(std::array<CardOpt_t, 5>()), hand_info(std::array<CardInfoOpt_t, 5>()) {}

    void setCard (const CardOpt_t& card, CardNum_t index) { hand[index] = card; }
    const Hand_t& getHand() const { return hand; }

    const HandInfo_t& getHandInfo() const { return hand_info; }
    void setHandInfo(const CardInfoOpt_t& info, CardNum_t index) { hand_info[index] = info; }
private:
    Hand_t hand;
    HandInfo_t hand_info;
};

#endif