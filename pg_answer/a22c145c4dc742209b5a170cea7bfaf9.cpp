#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    std::cout << *a.rbegin();
    std::for_each(a.rbegin() + 1, a.rend(), [](int i) { std::cout << " " << i; });
}