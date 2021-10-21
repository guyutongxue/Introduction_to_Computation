#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int bad, good;
        std::cin >> bad >> good;
        int hours{0};
        while (bad > 0) {
            bad -= good;
            bad *= 2;
            good *= 1.05;
            if (bad > 1'000'000) {
                bad = 1'000'000;
            }
            hours++;
        }
        std::cout << hours << std::endl;
    }
}