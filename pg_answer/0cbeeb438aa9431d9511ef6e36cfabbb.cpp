#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }

    int max = *std::max_element(a.begin(), a.end());
    int min = *std::min_element(a.begin(), a.end());
    std::cout << *std::min_element(a.begin(), a.end(), [max, min](int x, int y) {
        return std::abs(std::abs(x - max) - std::abs(x - min)) <
               std::abs(std::abs(y - max) - std::abs(y - min));
    }) << std::endl;
}