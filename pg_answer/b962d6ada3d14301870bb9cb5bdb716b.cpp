#include <iostream>

int a[120][120]{};
bool notVisited[120][120]{};

enum class Direction { RIGHT, DOWN, LEFT, UP };

void turn(Direction& d) {
    int v{static_cast<int>(d)};
    v = (v + 1) % 4;
    d = static_cast<Direction>(v);
}
void next(int& r, int& c, Direction& d) {
    notVisited[r][c] = false;
begin:
    switch (d) {
        case Direction::RIGHT:
            if (notVisited[r][c + 1]) {
                c++;
                break;
            } else {
                turn(d);
                goto begin;
            }
        case Direction::DOWN:
            if (notVisited[r + 1][c]) {
                r++;
                break;
            } else {
                turn(d);
                goto begin;
            }
        case Direction::LEFT:
            if (notVisited[r][c - 1]) {
                c--;
                break;
            } else {
                turn(d);
                goto begin;
            }
        case Direction::UP:
            if (notVisited[r - 1][c]) {
                r--;
                break;
            } else {
                turn(d);
                goto begin;
            }
    }
}

int main() {
    int row, col;
    std::cin >> row >> col;
    for (int i{1}; i <= row; i++) {
        for (int j{1}; j <= col; j++) {
            std::cin >> a[i][j];
            notVisited[i][j] = true;
        }
    }
    int currentRow{1}, currentCol{0};
    Direction currentDirection{Direction::RIGHT};
    for (int i{0}; i < row * col; i++) {
        next(currentRow, currentCol, currentDirection);
        std::cout << a[currentRow][currentCol] << std::endl;
    }
}