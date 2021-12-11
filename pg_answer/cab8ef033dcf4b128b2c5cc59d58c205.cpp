#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 10 << std::endl;
        std::exit(0);
    }
    int a[10][25]{};
    for (int i{0}; i < 10; i++) {
        a[i][0] = 1;
    }
    for (int i{1}; i <= n; i++) {
        a[1][i] = a[8][i - 1] + a[6][i - 1];
        a[2][i] = a[7][i - 1] + a[9][i - 1];
        a[3][i] = a[4][i - 1] + a[8][i - 1];
        a[4][i] = a[3][i - 1] + a[9][i - 1] + a[0][i - 1];
        a[6][i] = a[1][i - 1] + a[7][i - 1] + a[0][i - 1];
        a[7][i] = a[2][i - 1] + a[6][i - 1];
        a[8][i] = a[1][i - 1] + a[3][i - 1];
        a[9][i] = a[2][i - 1] + a[4][i - 1];
        a[0][i] = a[4][i - 1] + a[6][i - 1];
    }
    int sum{0};
    for (int i{0}; i <= 9; i++) {
        sum += a[i][n - 1];
    }
    std::cout << sum << std::endl;
}