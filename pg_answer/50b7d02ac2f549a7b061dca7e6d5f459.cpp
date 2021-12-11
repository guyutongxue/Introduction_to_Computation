#include <iostream>
#include <algorithm>
#include <limits>

constexpr int MIN{std::numeric_limits<int>::min()};

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        int w[202][202]{};
        int f[202][202]{};
        for (int i{1}; i <= n; ++i) {
            int sum{};
            for (int j{1}; j <= m; ++j) {
                int x;
                std::cin >> x;
                w[i][j] = sum += x;
                f[i][j] = i == n ? 0 : MIN;
            }
        }
        std::fill(f[0], f[0] + 202, MIN);

        for (int i{n - 1}; i >= 0; i--) {
            for (int j{1}; j <= m; j++) {
                for (int k{1}; k <= m; k++) {
                    int l{std::min(j, k)}, r{std::max(j, k)};
                    f[i][j] = std::max(f[i][j], w[i + 1][r] - w[i + 1][l - 1] + f[i + 1][k]);
                }
            }
        }

        int ans{MIN};
        for (int i{1}; i <= m; i++) {
            ans = std::max(ans, f[0][i]);
        }
        std::cout << ans << std::endl;
    }
    
}