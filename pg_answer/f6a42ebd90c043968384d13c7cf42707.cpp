#include <iostream>

int main() {
    char comma;
    double x, y;
    std::cin >> x >> comma >> y;
    if (std::abs(x) < 1 && std::abs(y) < 1) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}