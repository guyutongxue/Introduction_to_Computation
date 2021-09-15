#include <iostream>
#include <algorithm>

int main() {
    int n;
    int a[1000]{};
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i{0}; i < n - 1; i++) {
        for (int j{1}; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
    for (int i{0}; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}