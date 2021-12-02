#include <iostream>

int m, n;
int h[205][205]{};
bool drown[205][205]{};

void dfs(int x, int y) {
    if (drown[x][y]) return;
    drown[x][y] = true;
    if (h[x][y] >= h[x - 1][y] && !drown[x - 1][y]) {
        h[x - 1][y] = h[x][y];
        dfs(x - 1, y);
    }
    if (h[x][y] >= h[x + 1][y] && !drown[x + 1][y]) {
        h[x + 1][y] = h[x][y];
        dfs(x + 1, y);
    }
    if (h[x][y] >= h[x][y - 1] && !drown[x][y - 1]) {
        h[x][y - 1] = h[x][y];
        dfs(x, y - 1);
    }
    if (h[x][y] >= h[x][y + 1] && !drown[x][y + 1]) {
        h[x][y + 1] = h[x][y];
        dfs(x, y + 1);
    }
}

int main() {
    int k;
    std::cin >> k;
    while (k--) {
        std::cin >> m >> n;
        for (int i{1}; i <= m; i++) {
            for (int j{1}; j <= n; j++) {
                std::cin >> h[i][j];
            }
        }
        for (int i{0}; i <= m; i++) {
            h[i][0] = h[i][n + 1] = 2000;
        }
        for (int i{0}; i <= n; i++) {
            h[0][i] = h[m + 1][i] = 2000;
        }

        int x, y, p;
        std::cin >> x >> y >> p;
        bool targetDrown{false};
        for (int i{0}; i < p; i++) {
            int sx, sy;
            std::cin >> sx >> sy;
            if (!targetDrown) {
                for (int j{0}; j < 205; j++) {
                    for (int k{0}; k < 205; k++) {
                        drown[j][k] = false;
                    }
                }
                dfs(sx, sy);
                targetDrown = drown[x][y];
            }
        }
        std::cout << (targetDrown ? "Yes" : "No") << std::endl;
    }
}