#include <iostream>

int a[200][200];
int square[200][200];

struct Point {
    int x, y;
};
struct Ans {
    Point leftDown;
    Point rightUp;
    int num;
};

int area(int x1, int y1, int x2, int y2) {
    if (x1 == 0 && y1 == 0)
        return square[x2][y2];
    if (x1 == 0)
        return square[x2][y2] - square[x2][y1 - 1];
    if (y1 == 0)
        return square[x2][y2] - square[x1 - 1][y2];
    return square[x2][y2] - square[x2][y1 - 1] - square[x1 - 1][y2] +
           square[x1 - 1][y1 - 1];
}

int main() {
    int n;
    std::cin >> n;
    Ans ans{};
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    square[0][0] = a[0][0];
    for (int i{1}; i < n; i++) {
        square[0][i] = square[0][i - 1] + a[0][i];
        square[i][0] = square[i - 1][0] + a[i][0];
    }
    for (int i{1}; i < n; i++) {
        for (int j{1}; j < n; j++) {
            square[i][j] = square[i - 1][j] + square[i][j - 1] -
                           square[i - 1][j - 1] + a[i][j];
        }
    }
    for (int x1{0}; x1 < n; x1++) {
        for (int y1{0}; y1 < n; y1++) {
            for (int x2{x1}; x2 < n; x2++) {
                for (int y2{y1}; y2 < n; y2++) {
                    int current{area(x1, y1, x2, y2)};
                    if (current > ans.num)
                        ans = {{x1, y1}, {x2, y2}, current};
                }
            }
        }
    }
    for (int i{ans.leftDown.x}; i <= ans.rightUp.x; i++) {
        for (int j{ans.leftDown.y}; j <= ans.rightUp.y; j++) {
            std::cout << a[i][j] << " \n"[j == ans.rightUp.y];
        }
    }
    std::cout << ans.num << std::endl;
}