#include <iostream>
#include <algorithm>

int a[110][110], map[110][110]{};
int ans{1};
int m, n;
int dirs[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(int y, int x) {
    int max{0};
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (map[y][x] != -1) {
        ans = std::max(ans, map[y][x]);
        return map[y][x];
    }

    for (int i{0}; i < 4; i++) {
        int ny{y + dirs[i][1]}, nx{x + dirs[i][0]};
        if (a[y][x] < a[ny][nx]) {
            max = std::max(max, dfs(ny, nx));
        }
    }
    map[y][x] = max + 1;
    ans = std::max(ans, map[y][x]);
    return map[y][x];
}
int main() {
    std::cin >> m >> n;
    for (int i{0}; i < m; i++) {
        for (int j{0}; j < n; j++) {
            std::cin >> a[i][j];
            map[i][j] = -1;
        }
    }
    for (int i{0}; i < m; i++) {
        for (int j{0}; j < n; j++) {
            if (map[i][j] == -1) dfs(i, j);
        }
    }
    std::cout << ans << std::endl;
}