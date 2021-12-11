#include <algorithm>
#include <iostream>
#include <limits>

constexpr int MAX{std::numeric_limits<int>::max()};

int main() {
    int n;
    int a[105];
    int f[105][105]{};
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i{0}; i < 105; i++) {
        for (int j{0}; j < 105; j++) {
            f[i][j] = i == j ? 0 : MAX;
        }
    }
    for (int i{0}; i < n - 1; i++) {
        f[i][i + 1] = a[i] + a[i + 1];
    }
    for (int i{2}; i < n; i++) {
        for (int j{0}; j + i < n; j++) {
            int sum{};
            for (int p{j}; p <= j + i; p++) {
                sum += a[p];
            }
            for (int k{0}; k < i; k++) {
                f[j][j + i] = std::min(f[j][j + i], f[j][j + k] + f[j + k + 1][j + i] + sum);
            }
        }
    }
    std::cout << f[0][n - 1] << std::endl;
}