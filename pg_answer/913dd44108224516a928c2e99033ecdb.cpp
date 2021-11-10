#include <iostream>
#include <limits>

int main() {
    int a[110][110], b[110][110];
    int m, n, r, s;
    std::cin >> m >> n;
    for (int i{0}; i < m; ++i) {
        for (int j{0}; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }
    std::cin >> r >> s;
    for (int i{0}; i < r; ++i) {
        for (int j{0}; j < s; ++j) {
            std::cin >> b[i][j];
        }
    }
    int min_sum{std::numeric_limits<int>::max()};
    int min_i{0}, min_j{0};
    for (int i{0}; i <= m - r; ++i)
        for (int j{0}; j <= n - s; ++j) {
            int sum{0};
            for (int p{0}; p < r; ++p) {
                for (int q{0}; q < s; ++q) {
                    sum += abs(a[i + p][j + q] - b[p][q]);
                }
            }
            if (sum < min_sum) {
                min_sum = sum;
                min_i = i;
                min_j = j;
            }
        }
    for (int p{0}; p < r; ++p) {
        for (int q{0}; q < s; ++q) {
            std::cout << a[min_i + p][min_j + q] << ' ';
        }
        std::cout << std::endl;
    }
}