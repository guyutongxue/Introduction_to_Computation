#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    for (int i{0}; i <= 11; i++) {
        for (int j{0}; j <= 11; j++) {
            if (a >> i == b >> j) {
                std::cout << (a >> i) << std::endl;
                std::exit(0);
            }
        }
    }
}