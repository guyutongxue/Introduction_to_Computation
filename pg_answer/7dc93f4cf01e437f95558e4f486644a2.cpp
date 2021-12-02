#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int x{-1}, l{0};
    int ans{0};
    for (int i{0}; i < n; i++) {
        int y;
        std::cin >> y;
        if (y - x == 1) {
            l++;
        } else {
            ans = std::max(ans, l);
            l = 1;
        }
        x = y;
    }
    ans = std::max(ans, l);
    std::cout << ans << std::endl;
}