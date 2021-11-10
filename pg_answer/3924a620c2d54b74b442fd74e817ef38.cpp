#include <iostream>

int main() {
    bool a[102]{};
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        a[x] = true;
    }
    for (int i{1}; i <= n; i++) {
        if (!a[i]) {
            std::cout << i << std::endl;
        }
    }
}