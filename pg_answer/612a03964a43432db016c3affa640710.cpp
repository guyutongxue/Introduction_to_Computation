#include <iostream>

bool prime(int x) {
    if (x < 2) return false;
    for (int i{2}; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int reverse(int x) {
    int res{0};
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}


int main() {
    int p, q;
    char comma;
    std::cin >> p >> comma >> q;
    bool isFirst{true};
    for (int a{p}; a <= q; a++) {
        int b{reverse(a)};
        if (a <= b && b <= q && prime(a) && prime(b)) {
            if (isFirst) {
                isFirst = false;
            } else {
                std::cout << ",";
            }
            std::cout << a;
        }
    }
    if (isFirst) {
        std::cout << "NULL";
    }
}