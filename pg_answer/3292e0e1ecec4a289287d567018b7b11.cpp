#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    if (n == 0) {
        std::cout << "None" << std::endl;
        std::exit(0);
    }
    for (auto& i : v) {
        std::cin >> i;
    }
    for (const auto& i : v) {
        std::cout << std::count_if(v.begin(), v.end(), [i](int j) { return j < i; }) << std::endl;
    }
}