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
    std::vector<int> sum{a[0], std::max(a[0], a[1])};
    for (int i{2}; i < n; i++) {
        sum.push_back(std::max(a[i] + sum[i - 2], sum[i - 1]));
    }
    std::cout << sum.back() << std::endl;
}