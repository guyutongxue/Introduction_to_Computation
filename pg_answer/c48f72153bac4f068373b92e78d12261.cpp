#include <iostream>

int main() {
    int a[32]{1, 1};
    int n;
    std::cin >> n;
    for (int i{2}; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    std::cout << a[n] << std::endl;
}