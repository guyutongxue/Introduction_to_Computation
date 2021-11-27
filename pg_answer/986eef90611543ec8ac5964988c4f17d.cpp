#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> dict(n);
    for (auto& i : dict) {
        std::cin >> i;
    }
    int len{dict[0].size()};
    while (m--) {
        std::string dest;
        std::cin >> dest;
        if (dest.size() % len != 0) {
            std::cout << "No" << std::endl;
            continue;
        }
        while (dest.size()) {
            std::string sub{dest.substr(dest.size() - len)};
            auto it = std::find(dict.begin(), dict.end(), sub);
            if (it != dict.end()) {
                dest.erase(dest.size() - len);
            } else {
                std::cout << "No" << std::endl;
                goto next;
            }
        }
        std::cout << "Yes" << std::endl;
    next:;
    }
}