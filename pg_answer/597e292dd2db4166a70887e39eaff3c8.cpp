#include <iostream>
int month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthL[13]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
// In Europe 1582.10.5 -> 1582.10.14
// In U.K. 1752.9.2 -> 1752.9.14
int getDates(int y, int m, int d) {
    int gap{0};
    for (int i{1753}; i < y; i++) {
        if (isLeap(i))
            gap += 366;
        else
            gap += 365;
    }
    if (isLeap(y)) {
        for (int i = 1; i < m; i++) {
            gap += monthL[i];
        }
    } else {
        for (int i = 1; i < m; i++) {
            gap += month[i];
        }
    }
    gap += d;
    return gap;
}
int main() {
    int a, b, c;
    int d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    std::cout << getDates(d, e, f) - getDates(a, b, c)  << std::endl;
}