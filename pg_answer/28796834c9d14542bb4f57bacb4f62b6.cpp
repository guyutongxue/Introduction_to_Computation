#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int inversion(const std::string& s) {
    int inv{0};
    for (int i{0}; i < s.size(); ++i) {
        for (int j{i + 1}; j < s.size(); ++j) {
            if (s[i] > s[j]) {
                ++inv;
            }
        }
    }
    return inv;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> v(m);
    for (auto& s : v) {
        std::cin >> s;
    }
    std::sort(v.begin(), v.end(), [](auto& a, auto& b) { return inversion(a) < inversion(b); });
    for (auto& s : v) {
        std::cout << s << std::endl;
    }
}