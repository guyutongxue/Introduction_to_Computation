#include <iostream>

int main() {
    int n, m;
    int sum{0};
    int a[200]{};
    std::cin >> n >> m;
    while (n--) {
        int i, j;
        std::cin >> i >> j;
        a[j] = i;
    }
    for (int i = 199; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (m < a[i]) break;
        m -= a[i];
        sum++;
    }
    std::cout << sum << std::endl;
}