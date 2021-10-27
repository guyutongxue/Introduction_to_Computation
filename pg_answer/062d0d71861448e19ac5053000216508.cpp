#include <map>
#include <iostream>

int main() {
    std::map<int, int> m;
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        m[x]++;
    }
    for (auto& i : m) {
        std::cout << i.first << ":" << i.second << std::endl;
    }
}