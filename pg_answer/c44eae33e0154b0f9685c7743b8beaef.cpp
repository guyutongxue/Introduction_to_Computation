#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    while (n--) {
        double f;
        std::cin >> f;
        std::cout << 5 * (f - 32) / 9 << std::endl;
    }
}