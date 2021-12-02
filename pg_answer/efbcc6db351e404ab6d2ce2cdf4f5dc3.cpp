#include <iostream>
#include <algorithm>

int a[1000]{};
int inc[1000]{};
int dec[1000]{};
int main() {
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < i; j++) {
            if (a[i] > a[j]) {
                inc[i] = std::max(inc[i], inc[j] + 1);
            }
        }
    }
    for (int i{n - 1}; i >= 0; i--) {
        for (int j{n - 1}; j > i; j--) {
            if (a[i] > a[j]) {
                dec[i] = std::max(dec[i], dec[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, inc[i] + dec[i]);
    }
    std::cout << n - 1 - ans << std::endl;
}