#include <cmath>
#include <iostream>

constexpr double PI{3.14159};

int main() {
    int h, r;
    std::cin >> h >> r;
    std::cout << std::ceil(20'000 / (h * r * r * PI)) << std::endl;
}