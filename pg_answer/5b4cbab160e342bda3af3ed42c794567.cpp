#include <iostream>
#include <algorithm>

int main() {
    int l, m;
    std::cin >> l >> m;
    bool trees[10002]{};
    for (int i{0}; i < m; i++) {
        int left, right;
        std::cin >> left >> right;
        for (int j{left}; j <= right; j++) {
            trees[j] = true;
        }
    }
    std::cout << std::count(trees, trees + l + 1, false) << std::endl;
    
}