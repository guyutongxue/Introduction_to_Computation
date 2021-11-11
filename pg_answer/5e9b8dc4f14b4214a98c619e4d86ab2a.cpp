#include <iostream>

enum Status { EMPTY, FILLED, VISITED };

Status a[102][102]{};

void search(int x, int y) {
    a[x][y] = VISITED;
    if (a[x + 1][y] == FILLED) search(x + 1, y);
    if (a[x][y + 1] == FILLED) search(x, y + 1);
    if (a[x - 1][y] == FILLED) search(x - 1, y);
    if (a[x][y - 1] == FILLED) search(x, y - 1);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            int x;
            std::cin >> x;
            a[i][j] = static_cast<Status>(x);
        }
    }
    int cnt{0};
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            if (a[i][j] == FILLED) {
                cnt++;
                search(i, j);
            }
        }
    }
    std::cout << cnt << std::endl;
}