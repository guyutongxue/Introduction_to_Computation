#include <iostream>
#include <algorithm>

int main() {
    int a[16]{};
    int n;
    std::cin >> n;
    while (n--) {
        int i;
        std::cin >> i;
        a[i]++;
    };
    std::cout << std::max_element(a, a + 16) - a << std::endl;
}