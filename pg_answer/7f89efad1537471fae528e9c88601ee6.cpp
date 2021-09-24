#include <iostream>

int main() {
    int h, w;
    char fill;
    int isFilled;
    while (std::cin >> h >> w >> fill >> isFilled, h) {
        if (isFilled) {
            for (int i{0}; i < h; i++) {
                for (int j{0}; j < w; j++) {
                    std::cout << fill;
                }
                std::cout << '\n';
            }
        } else {
            for (int i{0}; i < w; i++) {
                std::cout << fill;
            }
            std::cout << '\n';
            for (int i{0}; i < h - 2; i++) {
                std::cout << fill;
                for (int j{0}; j < w - 2; j++) {
                    std::cout << ' ';
                }
                std::cout << fill << '\n';
            }
            for (int i{0}; i < w; i++) {
                std::cout << fill;
            }
            std::cout << '\n';
        }
    }
}