#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std::literals;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 1);
    auto result{std::accumulate(v.begin(), v.end(), ""s,
                                [](auto& a, auto& b) { return a + std::to_string(b); })};
    char target;
    std::cin >> target;
    std::cout << std::count(result.begin(), result.end(), target) << std::endl;
}