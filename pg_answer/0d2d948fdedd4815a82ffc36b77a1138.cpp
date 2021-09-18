#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int e{0}, cnt{b};
    while (b) {
        e += b;
        cnt += b = e / a;
        e %= a;
    }
    std::cout << cnt << std::endl;
}