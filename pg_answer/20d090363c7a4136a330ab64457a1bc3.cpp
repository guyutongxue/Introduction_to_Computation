#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    for (int i{0}, j{n - 1}; i <= j; i++, j--) {
        std::cout << a[j] << std::endl;
        if (i != j) {
            std::cout << a[i] << std::endl;
        }
    }
}