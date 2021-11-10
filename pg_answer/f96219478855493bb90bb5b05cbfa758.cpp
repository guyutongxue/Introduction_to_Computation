#include <iostream>
#include <string>

bool isLeap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    const int d[2][13]{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    std::string s{};
    for (int y{2021}; y <= 2099; y++) {
        for (int m{1}; m <= 12; m++) {
            int daysInMonth{isLeap(y) ? d[1][m] : d[0][m]};
            for (int d{1}; d <= daysInMonth; d++) {
                s += std::to_string(y * 10000 + m * 100 + d);
            }
        }
    }
    int n;
    std::cin >> n;
    while (n--) {
        std::string t;
        std::cin >> t;
        std::cout << s.find(t, 16) - 15 << std::endl;
    }
}