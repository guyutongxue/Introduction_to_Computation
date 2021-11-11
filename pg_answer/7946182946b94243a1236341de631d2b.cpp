#include <algorithm>
#include <iostream>

enum Status { AVAILABLE, VISITED, DEST };

Status a[52][52]{};
bool search(int x, int y) {
    if (a[x][y] == VISITED) return false;
    if (a[x][y] == DEST) return true;
    a[x][y] = VISITED;
    return search(x + 1, y) || search(x, y + 1) || search(x - 1, y) || search(x, y - 1);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int sx{}, sy{};
    for (int i = 0; i <= std::max(n, m); i++) {
        a[0][i] = a[i][0] = a[n + 1][i] = a[i][m + 1] = VISITED;
    }
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            int x;
            std::cin >> x;
            switch (x) {
                case 0: a[i][j] = AVAILABLE; break;
                case 1: a[i][j] = VISITED; break;
                case 2:
                    a[i][j] = AVAILABLE;
                    sx = i, sy = j;
                    break;
                case 3: a[i][j] = DEST; break;
            }
        }
    }
    std::cout << (search(sx, sy) ? "Yes" : "No") << std::endl;
}