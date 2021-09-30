#include <iostream>

double newtonSqrt(double x, int& cnt) {
    if (x == 0) return 0;
    double last{0.0};
    double res{1.0};
    while (std::abs(res - last) >= 1e-6) {
        last = res;
        res = (res + x / res) / 2;
        cnt++;
    }
    return res;
}

int main() {
    int n;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    while (std::cin >> n) {
        int cnt{0};
        auto root{newtonSqrt(n, cnt)};
        std::cout << cnt << " " << root << std::endl;
    }
}