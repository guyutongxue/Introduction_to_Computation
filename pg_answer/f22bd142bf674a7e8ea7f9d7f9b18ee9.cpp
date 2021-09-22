#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    int max{*std::max_element(a.begin(), a.end())};
    std::cout << std::accumulate(a.begin(), a.end(), 0, [&](int x, int y) {
        return y == max ? x : x + y;
    }) << std::endl;
}