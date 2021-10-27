#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


int main() {
    int n;
    std::cin >> n;
    for (int k{n / 2}; k >= 1; k--) {
        if (gcd(n, k) == 1) {
            std::cout << k << std::endl;
            std::exit(0);
        }
    }
}