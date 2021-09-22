#include <iostream>

constexpr const double PRICES[]{28.9, 32.7, 45.6, 78.0, 35.0, 86.2, 27.8, 43.0, 56.0, 65.0};

int main() {
    int k;
    std::cin >> k;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    while (k--) {
        double sum{0.0};
        for (int i{0}; i < 10; i++) {
            int num;
            std::cin >> num;
            sum += num * PRICES[i];
        }
        std::cout << sum << std::endl;
    }
}