#include <algorithm>
#include <iostream>

int a[100][100];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    int ans{0};
    for (int i{0}; i < n; i++) {
        int dp[100][100];
        for (int j{0}; j < m; j++) {
            dp[j][j] = a[i][j] * m;
        }
        for (int j{1}; j < m; j++) {
            for (int k{0}; k < m - j; k++) {
                dp[k][k + j] = std::max(dp[k + 1][k + j] + a[i][k] * (m - j),
                                        dp[k][k + j - 1] + a[i][k + j] * (m - j));
            }
        }
        ans += dp[0][m - 1];
    }
    std::cout << ans << std::endl;
}