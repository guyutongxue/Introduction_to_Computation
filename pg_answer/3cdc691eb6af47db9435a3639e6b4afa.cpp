#include <iostream>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n, n) {
        int last{-1}, current{1}, answer{1};
        for (int i{0}; i < n; i++) {
            int x;
            std::cin >> x;
            if (x == last) {
                current++;
            } else {
                last = x;
                current = 1;
            }
            answer = std::max(answer, current);
        }
        std::cout << answer << std::endl;
    }
}