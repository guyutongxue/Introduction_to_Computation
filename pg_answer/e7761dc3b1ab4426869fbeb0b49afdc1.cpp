#include <iostream>

int gcd(int a, int b) {
    if (a < b) std::swap(a, b);
    int r{a % b};
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        a /= gcd(a, b);
        b /= gcd(a, b);
        int d{0}, res{0};
        while (a != 1 || b != 1) {
            if (a > b) {
                a -= b;
                res += (1 << d);
            } else {
                b -= a;
            }
            d++;
        }
        std::cout << (1 << d) + res << std::endl;
    }
}