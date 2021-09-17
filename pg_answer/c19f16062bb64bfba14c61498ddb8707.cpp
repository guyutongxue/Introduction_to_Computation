#include <iostream>

int main() {
    int n;
    int sum;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        int age;
        std::cin >> age;
        sum += age;
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << 1.0 * sum / n << std::endl;
}