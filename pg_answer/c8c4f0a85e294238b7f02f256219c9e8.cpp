#include <iostream>
int main() {
    bool a[1002]{};
    int n;
    std::cin >> n;
    for (int i{2}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            if (j % i == 0) {
                a[j] ^= true;
            }
        }
    }
    for (int i{1}; i <= n; i++) {
        if (a[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}