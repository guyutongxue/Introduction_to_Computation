#include <iostream>

enum class Pos { EMPTY = 0, BLACK = -1, WHITE = 1 };
Pos chess[50][50]{};
int N;

bool judge(int row, int col) {
    int flag{0};
    Pos color{chess[row][col]};
    const int DELTA[4][2]{{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    flag = 0;
    for (int i{0}; i < 4; i++) {
        flag = 0;
        for (int p{-4}; p <= 4; p++) {
            int deltaX = p * DELTA[i][0], deltaY = p * DELTA[i][1];
            if (row + deltaX >= N || row + deltaX < 0 || col + deltaY >= N || col + deltaY < 0)
                continue;
            if (chess[row + deltaX][col + deltaY] == color)
                flag++;
            else
                flag = 0;
            if (flag >= 5) return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> N >> n;
    int col, row;
    for (int i{1}; i <= n; i++) {
        std::cin >> row >> col;
        if (i % 2 != 0) {
            chess[row][col] = Pos::BLACK;
            if (judge(row, col)) {
                std::cout << i << " 0" << std::endl;
                std::exit(0);
            }
        } else {
            chess[row][col] = Pos::WHITE;
            if (judge(row, col)) {
                std::cout << i << " 1" << std::endl;
                std::exit(0);
            }
        }
    }
}