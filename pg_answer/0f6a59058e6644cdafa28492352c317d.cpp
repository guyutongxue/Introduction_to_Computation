#include <cstring>
#include <iostream>

char a[102][102];
bool mk[102][102][4];
bool isFound{false};

int mod(int p) {
  return (p % 4 + 4) % 4;
}

void step(int p, int& x, int& y) {
    switch (mod(p)) {
        case 0: y++; break;
        case 1: x--; break;
        case 2: y--; break;
        case 3: x++; break;
    }
}

bool search(int x, int y, int p) {
    step(p, x, y);
    if (a[x][y] == '#') return false;
    if (a[x][y] == 'T') {
        isFound = true;
        return true;
    }
    if (mk[x][y][mod(p)]) return true;
    mk[x][y][mod(p)] = true;
    return search(x, y, p + 1) || search(x, y, p) || search(x, y, p - 1) || search(x, y, p - 2);
}
int main() {
    int n, m;
    while (std::cin >> n >> m) {
        std::memset(mk, 0, sizeof(mk));
        int x, y, p;
        for (int i{1}; i <= n; i++) {
            for (int j{1}; j <= m; j++) {
                std::cin >> a[i][j];
                if (a[i][j] == 'S') {
                    x = i;
                    y = j;
                    a[i][j] = '.';
                }
            }
        }
        char c;
        std::cin >> c;
        switch (c) {
            case 'E': p = 0; break;
            case 'N': p = 1; break;
            case 'W': p = 2; break;
            case 'S': p = 3; break;
        }
        mk[x][y][p] = true;
        isFound = false;
        search(x, y, p + 1) || search(x, y, p) || search(x, y, p - 1) || search(x, y, p - 2);
        std::cout << (isFound ? "YES" : "NO") << std::endl;
    }
}