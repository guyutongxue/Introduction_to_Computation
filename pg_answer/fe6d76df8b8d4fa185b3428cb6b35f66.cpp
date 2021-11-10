#include <iostream>
#include <algorithm>

int main() {
    int n, k, h;
    int a[1001]{}, b[1002]{};
    std::cin >> n >> k >> h;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i{1}; i <= n + 1; i++) {
        std::cin >> b[i];
    }
    int sum{0};
    auto i{std::upper_bound(&a[1], &a[n + 1], h / k) - &a[0]};
    for (int j = 1; j < i; ++j) {
        sum += k * (a[j] - a[j - 1]) * b[j];
    }
    sum += (h - k * a[i - 1]) * b[i];
    std::cout << sum << std::endl;
}