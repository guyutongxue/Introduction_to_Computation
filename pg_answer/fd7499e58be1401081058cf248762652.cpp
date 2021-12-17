#include <algorithm>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a[55];
    bool op[55]{};
    for (int i{0}; i < n; i++) {
        char ch;
        std::cin >> a[i] >> ch;
        op[i] = ch == '*';
    }
    int ans{};
    int r{n};
    while (r--) {
        int f[55][55]{};
        for (int i{0}; i < n; i++) {
            f[i][i] = a[i];
        }
        for (int i{2}; i <= n; i++) {
            for (int j{0}; i + j - 1 < n; j++) {
                int left{j}, right{i + j - 1};
                for (int k{left}; k < right; k++) {
                    if (op[k]) {
                        f[left][right] = std::max(f[left][k] * f[k + 1][right], f[left][right]);
                    } else {
                        f[left][right] = std::max(f[left][k] + f[k + 1][right], f[left][right]);
                    }
                }
            }
        }
        ans = std::max(ans, f[0][n - 1]);
        std::rotate(a, a + 1, a + n);
        std::rotate(op, op + 1, op + n);
    }
    std::cout << ans << std::endl;
}