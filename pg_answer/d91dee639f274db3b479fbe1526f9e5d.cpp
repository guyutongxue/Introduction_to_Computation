#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << std::max(2, static_cast<int>(std::ceil(n * 2.0 / k))) << std::endl;
}