#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::cin >> t >> n;
    std::vector<int> r;
    for (int i{2}; i <= n; i++) {
        int s;
        std::cin >> s;
        auto len{r.size()};
        for (auto j{1u}; j <= len; j++) {
            r.push_back(r[j] * s);
        }
        r.push_back(s);
    }
    for (auto i : r) {
        if (i == t) {
            std::cout << "YES" << std::endl;
            std::exit(0);
        }
    }
    std::cout << "NO" << std::endl;
}