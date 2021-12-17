#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    std::cin >> m;
    std::vector<int> b(m);
    for (auto& i : b) {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<int> c(n + m);
    std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    bool isFirst{true};
    for (auto& i : c) {
        if (isFirst) {
            isFirst = false;
        } else {
            std::cout << " ";
        }
        std::cout << i;
    }
}