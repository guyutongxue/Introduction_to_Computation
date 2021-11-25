#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    int cnt{0};
    for (int i{0}; i < n; i++) {
        for (int j{i + 1}; j < n; j++) {
            if (a[i] > a[j]) {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}