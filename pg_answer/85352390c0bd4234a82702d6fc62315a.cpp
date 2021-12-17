#include <algorithm>
#include <iostream>
#include <string>

int f[810][810]{};

int tran(char c) {
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C') return 2;
    if (c == 'T') return 3;
    return 0;
}
int main() {
    int nt;
    std::cin >> nt;
    for (int t{1}; t <= nt; t++) {
        std::cout << "Case #" << t << std::endl;
        int val[4][4];
        for (auto& i : val) {
            for (auto& j : i) {
                std::cin >> j;
            }
        }
        int d, n;
        std::cin >> d >> n;
        while (n--) {
            std::string as, bs;
            std::cin >> as >> bs;
            unsigned a[810]{}, b[810]{};
            std::transform(as.begin(), as.end(), a + 1, tran);
            std::transform(bs.begin(), bs.end(), b + 1, tran);
            f[0][0] = 0;
            for (auto i{1u}; i <= as.size(); i++) {
                f[i][0] = f[i - 1][0] + d;
            }
            for (auto j{1u}; j <= bs.size(); j++) {
                f[0][j] = f[0][j - 1] + d;
            }
            for (auto i{1u}; i <= as.size(); i++) {
                for (auto j{1u}; j <= bs.size(); j++) {
                    // std::max({a, b, c}) cause timeout
                    f[i][j] = std::max(std::max(f[i][j - 1] + d, f[i - 1][j] + d),
                                       f[i - 1][j - 1] + val[a[i]][b[j]]);
                }
            }
            std::cout << f[as.size()][bs.size()] << std::endl;
        }
    }
}