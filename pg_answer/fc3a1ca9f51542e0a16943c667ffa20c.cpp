#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<std::string> v(4);
    for (auto& i : v) {
        std::getline(std::cin, i);
    }
    int len = std::min_element(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    })->size();
    for (; len >= 0; len--) {
        const std::string p = v[0].substr(0, len);
        if (std::all_of(v.begin(), v.end(), [&](const std::string& s) {
            return s.substr(0, len) == p;
        })) {
            std::cout << p << std::endl;
            break;
        }
    }
}