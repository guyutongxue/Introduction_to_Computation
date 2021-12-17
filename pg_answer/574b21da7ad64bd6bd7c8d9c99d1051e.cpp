#include <iostream>

int a[110][110]{};
int f[110][110]{};

int main() {
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            if (i == 0 && j == 0) {
                f[i][j] = a[i][j];
            } else if (i > 0 && j == 0) {
                f[i][j] = f[i - 1][j] + a[i][j];
            } else if (i == 0 && j > 0) {
                f[i][j] = f[i][j - 1] + a[i][j];
            } else {
                f[i][j] = std::min(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        }
    }
    std::cout << f[n - 1][n - 1] << std::endl;
}