#include <iostream>

int n, k;

bool hasLeft(int num, int times) {
    if (!times) {
        return num != 0;
    }
    if ((num - k) % n) return false;
    return hasLeft((n - 1) * (num / n), times - 1);
}

int main() {
    std::cin >> n >> k;
    int i{0};
    while (!hasLeft(++i, n)) {
    }
    std::cout << i << std::endl;
}
