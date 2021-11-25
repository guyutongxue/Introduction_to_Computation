#include <algorithm>
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string s;
    std::cin >> s;
    int max{std::numeric_limits<int>::min()};
    int firstPos{s[0] == '-' ? 2 : 1};
    for (unsigned i{firstPos}; i < s.size(); i++) {
        for (unsigned j{i + 1}; j < s.size(); j++) {
            int a{std::stoi(s.substr(0, i))};
            int b{std::stoi(s.substr(i, j - i))};
            int c{std::stoi(s.substr(j))};
            max = std::max(max, a * b * c);
        }
    }
    std::cout << max << std::endl;
}