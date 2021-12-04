#include <algorithm>
#include <iostream>

int dp[200][20]{};

int main() {
    int n{}, m{};
    while (std::cin >> n >> m) {
        for (int i{0}; i <= n; i++) {
            for (int j{0}; j <= m; j++) {
                dp[i][j] = i;
            }
        }
        for (int i{2}; i <= n; i++) {
            for (int j{2}; j <= m; j++) {
                for (int k{1}; k < i; k++) {
                    dp[i][j] = std::min(dp[i][j], 1 + std::max(dp[k - 1][j - 1], dp[i - k][j]));
                }
            }
        }
        std::cout << dp[n][m] << std::endl;
    }
}