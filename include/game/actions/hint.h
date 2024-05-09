#ifndef HINT_H_
#define HINT_H_

class Hint
{
public:
    virtual CardInfo getInfoProvidedToCard(const Card& card) const = 0;
};

class ColorHint: Hint
{
public:
    ColorHint(CardColor_t color): color(color) {}

    CardInfo getInfoProvidedToCard(const Card& card) const override
    {
        CardInfo info;
        if (card.getColor() != this->color)
        {
            info.setColorInfo(this->color, false);
        }
        else
        {
            info.setColorInfo(RED, false);
            info.setColorInfo(BLUE, false);
            info.setColorInfo(WHITE, false);
            info.setColorInfo(GREEN, false);
            info.setColorInfo(YELLOW, false);
            info.setColorInfo(this->color, true);
        }
        return info;
    }

private:
    CardColor_t color;
};

class ValueHint: Hint
{
public:
    ValueHint(CardValue_t value): value(value) {}

    CardInfo getInfoProvidedToCard(const Card& card) const override
    {
        CardInfo info;
        if (card.getValue() != this->value)
        {
            info.setValueInfo(this->value, false);
        }
        else
        {
            info.setValueInfo(1, false);
            info.setValueInfo(2, false);
            info.setValueInfo(3, false);
            info.setValueInfo(4, false);
            info.setValueInfo(5, false);
            info.setValueInfo(this->value, true);
        }
        return info;
    }

private:
    CardValue_t value;
};

#endif