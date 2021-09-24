#include <iostream>

int read() {
    int x;
    x = std::cin.get();
    return x - '0';
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    int cnt{0};
    while (n--) {
        int k{read()};
        int h{read()};
        int d{read()};
        int m{read()};
        if (m - k - h - d > 0) {
            cnt++;
        }
        std::cin.ignore();
    }
    std::cout << cnt << std::endl;
}