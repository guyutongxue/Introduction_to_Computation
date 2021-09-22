#include <iostream>

class Hand {
public:
    enum HandType { ROCK, SCISSORS, PAPER };

private:
    HandType hand;

public:
    Hand() = default;

    friend std::istream& operator>>(std::istream& is, Hand& hand);

    bool operator<(const Hand& other) const {
        if (this->hand == PAPER && other.hand == ROCK) return false;
        if (this->hand == ROCK && other.hand == PAPER) return true;
        return this->hand > other.hand;
    }
};

std::istream& operator>>(std::istream& is, Hand& hand) {
    int no;
    is >> no;
    hand.hand = static_cast<Hand::HandType>(no);
    return is;
}

int main() {
    int n;
    std::cin >> n;
    int aSum{0}, bSum{0};
    while (n--) {
        Hand a, b;
        std::cin >> a >> b;
        if (a < b)
            bSum++;
        else if (b < a)
            aSum++;
    }
    if (aSum > bSum) std::cout << "A" << std::endl;
    else if (bSum > aSum) std::cout << "B" << std::endl;
    else std::cout << "Tie" << std::endl;
}