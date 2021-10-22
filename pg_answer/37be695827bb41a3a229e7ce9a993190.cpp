#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    double sum{1.10 * a + 1.20 * b + 22.50 * c + 8.80 * d};
    if (sum < 600) {
        std::cout << "UNDER" << std::endl;
    } else if (sum > 1000) {
        std::cout << "OVER" << std::endl;
    } else {
        std::cout << "FINE" << std::endl;
    }
}