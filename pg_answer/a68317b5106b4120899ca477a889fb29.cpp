#include <iostream>

int gcd(int a, int b) {
    int c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;
    int sumn{0}, sumd{1};
    while (n--) {
        int num, deno;
        char slash;
        std::cin >> num >> slash >> deno;
        (sumn *= deno) += num * sumd;
        sumd *= deno;
    }
    int g{gcd(sumd, sumn)};
    sumd /= g;
    sumn /= g;
    if (sumd > 1) {
        std::cout << sumn << '/' << sumd << std::endl;
    } else {
        std::cout << sumn << std::endl;
    }
}