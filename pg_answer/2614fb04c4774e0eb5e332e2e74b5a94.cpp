#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        int total;
        std::cin >> total;
        int a{total / 25};
        total %= 25;
        int b{total / 10};
        total %= 10;
        int c{total / 5};
        total %= 5;
        std::cout << i << " " << a << " QUARTER(S)," << b << " DIME(S)," << c << " NICKEL(S),"
                  << total << " PENNY(S)" << std::endl;
    }
}