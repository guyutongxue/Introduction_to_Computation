#include <algorithm>
#include <iostream>
#include <limits>

int a[5002], f[5002][3002];
int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i{1}; i <= n; i++) {
        f[i][0] = 0;
        for (int j{1}; j <= k; j++) {
            f[i][j] = std::numeric_limits<int>::max();
        }
    }
    for (int i{n}; i >= 1; i--) {
        for (int j{1}; j <= k; j++) {
            if (n - i + 1 >= 3 * j) {
                f[i][j] =
                    std::min(f[i + 2][j - 1] + (a[i + 1] - a[i]) * (a[i + 1] - a[i]), f[i + 1][j]);
            }
        }
    }
    std::cout << f[1][k] << std::endl;
}