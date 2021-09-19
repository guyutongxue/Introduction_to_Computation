#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> list;
    while (list.emplace_back(), std::getline(std::cin, list.back()))
        ;
    for (auto& s : list) {
        for (unsigned pos{0}; pos < s.length(); pos++) {
            std::string prefix{s.substr(0, pos)};
            bool isDup{std::any_of(list.begin(), list.end(), [&](const auto& b) {
                return s != b && prefix == b.substr(0, pos);
            })};
            if (!isDup) {
                std::cout << s << " " << prefix << std::endl;
                goto next_string;
            }
        }
        std::cout << s << " " << s << std::endl;
    next_string:;
    }
}