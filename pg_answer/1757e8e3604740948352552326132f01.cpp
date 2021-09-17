#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std::literals;

int gcd(int a, int b) {
    int c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (auto& i : input) {
        std::cin >> i;
    }
    std::sort(input.begin(), input.end());
    auto end{std::unique(input.begin(), input.end())};
    input.erase(end, input.end());
    std::vector<std::string> ans;
    for (auto i{input.begin()}; i != input.end(); i++) {
        for (auto j{i + 1}; j != input.end(); j++) {
            if (gcd(*i, *j) == 1) {
                ans.emplace_back(std::to_string(*i) + "/" + std::to_string(*j));
            }
        }
    }
    if (ans.size() == 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << std::accumulate(ans.begin(), ans.end(), ""s,
                                     [](const auto& a, const auto& b) {
                                         return a + (a.length() > 0 ? "," : "") + b;
                                     })
                  << std::endl;
    }
}