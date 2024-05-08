#ifndef CARD_H_
#define CARD_H_

enum CardColor_t 
{
    RED, BLUE, WHITE, GREEN, YELLOW
};

typedef unsigned char CardValue_t;

class Card
{
    public:
        Card(CardColor_t color, CardValue_t value): color(color), value(value) {}
        Card(const Card& card): color(card.getColor()), value(card.getValue()) {}
        const Card& operator=(const Card& other)
        {
            if (this == &other) { return *this; }
            this->setColor(other.getColor());
            this->setValue(other.getValue());
            return *this;
        }

        CardColor_t getColor() const { return color; }
        CardValue_t getValue() const { return value; } 

        void setColor(CardColor_t color) { this->color = color; }
        void setValue(CardValue_t value) { this->value = value; }
    private:
        CardColor_t color;
        CardValue_t value;
};

#endif