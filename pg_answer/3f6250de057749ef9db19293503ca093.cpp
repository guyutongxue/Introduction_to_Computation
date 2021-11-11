#include <iostream>

int factor(int x, int start) {
    int num{1};
    for (int i{start}; i * i <= x; ++i) {
        if (x % i == 0) {
            num += factor(x / i, i);
        }
    }
    return num;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int a;
        std::cin >> a;
        std::cout << factor(a, 2) << std::endl;
    }
}
