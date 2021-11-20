#include <iostream>

int n;
int ans{0};
char c[10][10]{};
bool visit[10]{};

void dfs(int l, int k) {
    if (k == 0) {
        ans++;
        return;
    }
    for (int i{l}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            if (c[i][j] == '.' || visit[j]) continue;
            visit[j] = true;
            dfs(i + 1, k - 1);
            visit[j] = false;
        }
    }
}

int main() {
    int k;
    while (std::cin >> n >> k, n != -1) {
        for (int i{0}; i < 10; i++) {
            visit[i] = false;
        }
        ans = 0;
        for (int i{0}; i < n; i++) {
            for (int j{0}; j < n; j++) {
                std::cin >> c[i][j];
            }
        }
        dfs(0, k);
        std::cout << ans << std::endl;
    }
}