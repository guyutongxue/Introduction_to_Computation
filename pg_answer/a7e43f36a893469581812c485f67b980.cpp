#include <algorithm>
#include <iostream>
#include <string>

int dp[22][22];

int main() {
    int t;
    std::cin >> t;
    std::cout.setf(std::ios::fixed);
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        for (unsigned i{0}; i <= a.size(); i++) {
            dp[i][0] = i;
        }
        for (unsigned i = 0; i <= b.size(); i++) {
            dp[0][i] = i;
        }

        for (unsigned i{1}; i <= a.size(); i++) {
            for (unsigned j{1}; j <= b.size(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        std::cout << 1.0 / (1 + dp[a.size()][b.size()]) << std::endl;
    }
}