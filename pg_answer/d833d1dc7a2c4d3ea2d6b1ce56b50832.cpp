#include <algorithm>
#include <iostream>
#include <limits>

int a[100010]{}, sum[100010]{};

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    int res{std::numeric_limits<int>::max()};
    for (int i{n - k}; i <= n; i++) {
        res = std::min(sum[i] - sum[i - n + k], res);
    }
    std::cout << sum[n] - res << std::endl;
}