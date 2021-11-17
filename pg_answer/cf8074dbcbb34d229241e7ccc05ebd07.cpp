#include <iostream>

char a[202][202]{};

void search(int x, int y) {
    a[x][y] = '-';
    for (int i{x - 1}; i <= x + 1; i++) {
        for (int j{y - 1}; j <= y + 1; j++) {
            if (!(i == x && j == y) && a[i][j] == '#') {
                search(i, j);
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }
    int cnt{0};
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= m; j++) {
            if (a[i][j] == '#') {
                cnt++;
                search(i, j);
            }
        }
    }
    std::cout << cnt << std::endl;
}