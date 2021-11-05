#include <algorithm>
#include <cmath>
#include <iostream>

bool matrix[22][22];
struct Point {
    int x;
    int y;
};
bool isOK(const Point& a, const Point& b) {
    return !std::any_of(matrix + a.x, matrix + b.x + 1, [&](auto& line) {
        return std::any_of(line + a.y, line + b.y + 1, [&](auto& c) { return c; });
    });
}
int getArea(const Point& a, const Point& b) {
    return isOK(a, b) ? (1 + abs(a.x - b.x)) * (1 + abs(a.y - b.y)) : 0;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    for (int i{1}; i <= m; i++) {
        for (int j{1}; j <= n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    int max{0};
    for (int i{1}; i <= m; i++) {
        for (int j{1}; j <= n; j++) {
            for (int k{i}; k <= m; k++) {
                for (int l{j}; l <= n; l++) {
                    max = std::max(max, getArea({i, j}, {k, l}));
                }
            }
        }
    }
    std::cout << max << std::endl;
}