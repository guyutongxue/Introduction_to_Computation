#include <algorithm>
#include <iostream>
#include <limits>

int n;
int m[9][9]{};
int trans[9]{};

int search(int k) {
    if (k == 0) {
        int max{-1};
        for (int j{0}; j < n; j++) {
            int sum{0};
            for (int i{0}; i < n; i++) {
                sum += m[i][(j + trans[i]) % n];
            }
            max = std::max(max, sum);
        }
        return max;
    }
    int min{std::numeric_limits<int>::max()};
    for (int i{0}; i < n; i++) {
        trans[k] = i;
        min = std::min(min, search(k - 1));
    }
    return min;
}

int main() {
    while (std::cin >> n, n != -1) {
        for (int i{0}; i < n; i++) {
            for (int j{0}; j < n; j++) {
                std::cin >> m[i][j];
            }
        }
        std::cout << search(n) << std::endl;
    }
}