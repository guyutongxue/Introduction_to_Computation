#include <iostream>

int month[2][13]{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
int main() {
    int y, m, d;
    std::cin >> y >> m >> d;
    int gap{0};
    for (int i = 1990; i < y; i++) {
        if (isLeap(i))
            gap += 366;
        else
            gap += 365;
    }
    int leap{isLeap(y)};
    for (int i{1}; i < m; i++) {
        gap += month[leap][i];
    }
    gap += d - 1;
    if (gap % 5 <= 2)
        std::cout << "fishing" << std::endl;
    else
        std::cout << "sleeping" << std::endl;
}