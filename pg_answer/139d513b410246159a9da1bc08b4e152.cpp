#include <iostream>
#include <algorithm>

int cnt_vlg, cnt_scl;
int d[505]{};
int f[505][505]{};

int main() {
    std::cin >> cnt_vlg >> cnt_scl;
    for (int i{2}; i <= cnt_vlg; i++) {
        int a;
        std::cin >> a;
        d[i] = d[i - 1] + a;
    }

    for (int i{2}; i <= cnt_vlg; i++) {
        f[i][1] = f[i - 1][1] + d[i] - d[(1 + i) / 2];
    }

    for (int i{2}; i <= cnt_vlg; i++) {
        for (int j{2}; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1];
            int next_d{0};
            for (int k{i - 1}; k >= 1; k--) {
                next_d += std::abs(d[k] - d[(1 + i + k) / 2]);
                f[i][j] = std::min(f[i][j], next_d + f[k - 1][j - 1]);
            }
        }
    }
    std::cout << f[cnt_vlg][cnt_scl];
}