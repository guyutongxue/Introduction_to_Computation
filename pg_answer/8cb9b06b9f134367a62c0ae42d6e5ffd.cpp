#include <algorithm>
#include <numeric>
#include <iostream>
#include <array>

int n, m;
int maxstamp;
int r;
constexpr int MAXN{1000};
const int INF{0x3fffffff};
int x[MAXN];
std::array<int, MAXN> y;
void dfs(int cur) {
    if (cur >= n) {
        if (r > maxstamp) maxstamp = r;
        return;
    }
    auto backup_y{y};
    auto backup_r{r};
    for (int i{x[cur - 1] + 1}; i <= r + 1; i++) {
        x[cur] = i;
        for (int j{0}; j <= x[cur - 1] * (m - 1); j++) {
            if (y[j] >= m) {
                continue;
            }
            for (int num{1}; num <= m - y[j]; num++) {
                if (j + x[cur] * num < MAXN) {
                    y[j + x[cur] * num] = std::min(y[j + x[cur] * num], y[j] + num);
                }
            }
        }
        while (y[r + 1] < INF) {
            r++;
        }
        dfs(cur + 1);
        y = backup_y;
        r = backup_r;
    }
}
int main() {
    while (std::cin >> n >> m, n) {
        std::fill(y.begin(), y.end(), INF);
        maxstamp = 0;
        x[0] = 1;
        r = m;
        std::iota(y.begin(), y.begin() + m + 1, 0);
        dfs(1);
        std::cout << maxstamp << std::endl;
    }
}