#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::unordered_map<std::string, std::pair<int, int>> m;
    for (unsigned i{0}; i < s.length() - n + 1; i++) {
        std::string sub{s.substr(i, n)};
        if (m.count(sub) == 0) {
            m.insert({sub, {1, i}});
        } else {
            m[sub].first++;
        }
    }

    int max{std::max_element(m.begin(), m.end(), [](const auto& a, const auto& b) {
        return a.second.first < b.second.first;
    })->second.first};

    if (max <= 1) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << max << std::endl;

        std::vector<int> result;
        for (const auto& i : m) {
            if (i.second.first == max) {
                result.push_back(i.second.second);
            }
        }
        std::sort(result.begin(), result.end());
        for (const auto& i : result) {
            std::cout << s.substr(i, n) << std::endl;
        }
    }
}