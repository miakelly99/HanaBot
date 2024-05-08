#include "card.h"

#ifndef CARD_INFO_H_
#define CARD_INFO_H_

class CardInfo
{
public:
    CardInfo(): value_info({true, true, true, true, true}), color_info({true, true, true, true, true}) {}
    CardInfo(const CardInfo& other)
    {
        this->value_info = std::array<bool, 5>(other.value_info);
        this->color_info = std::array<bool, 5>(other.color_info);
    }

    const CardInfo& operator=(const CardInfo& other)
    {
        if (this == &other) { return *this; }
        this->value_info = std::array<bool, 5>(other.value_info);
        this->color_info = std::array<bool, 5>(other.color_info);
        return *this;
    }

    bool getValueInfo(CardValue_t value)
    {
        return value_info[value-1];
    }

    bool getColorInfo(CardColor_t color)
    {
        return color_info[color];
    }

    void setValueInfo(CardValue_t value, bool info)
    {
        value_info[value - 1] = info;
    }

    void setColorInfo(CardColor_t color, bool info)
    {
        color_info[color] = info;
    }

    CardInfo operator+ (const CardInfo& other) const
    {
        CardInfo new_info;
        for (unsigned int i = 0; i < 5; i++)
        {
            new_info.value_info[i] = this->value_info[i] & other.value_info[i];
            new_info.color_info[i] = this->color_info[i] & other.color_info[i];
        }
        return new_info;
    }
private:
    std::array<bool, 5> value_info;
    std::array<bool, 5> color_info;
};

#endif