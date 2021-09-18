#include <iostream>
#include <cmath>

int main() {
    int history, distance;
    std::cin >> history >> distance;
    int cost;
    if (distance <= 6) {
        cost = 3;
    } else if (distance <= 12) {
        cost = 4;
    } else if (distance <= 32) {
        cost = 4 + std::ceil((distance - 12) / 10.0);
    } else {
        cost = 6 + std::ceil((distance - 32) / 20.0);
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    if (history < 100 || history >= 400) {
        std::cout << 1.0 * cost << std::endl;
    } else if (history < 150) {
        std::cout << 0.8 * cost << std::endl;
    } else {
        std::cout << 0.5 * cost << std::endl;
    }
}