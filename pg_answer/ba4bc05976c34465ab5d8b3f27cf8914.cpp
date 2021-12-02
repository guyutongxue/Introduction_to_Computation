#include <iostream>
#include <vector>

constexpr const int MAX_N{1 << 20};  // 4 ^ 10
constexpr const int STEPS[16][2]{{0, 0}, {1, 0}, {0, 1}, {2, 0}, {1, 1}, {0, 2}, {3, 0}, {2, 1},
                                 {1, 2}, {0, 3}, {3, 1}, {2, 2}, {1, 3}, {3, 2}, {2, 3}, {3, 3}};

int v;
std::vector<std::vector<int>> a;
void save(int d, int sx, int sy) {
    if (d == 0) {
        for (auto& i : STEPS) {
            a[sx + i[0]][sy + i[1]] = v++;
        }
        return;
    }
    int step{1 << (2 * d)};  // 4 ^ d
    for (auto& i : STEPS) {
        save(d - 1, sx + i[0] * step, sy + i[1] * step);
    }
}

int main() {
    int n;
    while (std::cin >> n, n) {
        v = 0;
        a.resize(1 << (2 * n));
        for (auto& i : a) {
            i.resize(1 << (2 * n));
        }
        save(n - 1, 0, 0);
        int x, y;
        std::cin >> x >> y;
        std::cout << a[x][y] << std::endl;
    }
    
}