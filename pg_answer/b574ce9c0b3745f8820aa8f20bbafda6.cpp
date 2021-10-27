#include <iostream>

constexpr const int REMAINDER[13]{0, 3, 3, 6, 8, 11, 13, 16, 19, 21, 24, 26, 29};
constexpr const int REMAINDER_LEAP[13]{0, 3, 4, 7, 9, 12, 14, 17, 20, 22, 25, 27, 30};

bool isLeap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int y, m1, m2;
        std::cin >> y >> m1 >> m2;
        const int delta{isLeap(y) ? (REMAINDER_LEAP[m1 - 1] - REMAINDER_LEAP[m2 - 1])
                                  : (REMAINDER[m1 - 1] - REMAINDER[m2 - 1])};
        if (delta % 7 == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}