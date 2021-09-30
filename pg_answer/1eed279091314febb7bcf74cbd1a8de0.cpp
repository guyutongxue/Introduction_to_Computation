#include <iostream>
#include <bitset>
#include <algorithm>

constexpr int MAX_SIZE{101};

int main() {
    std::bitset<MAX_SIZE> bs;
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        bs.flip(x);
    }
    for (int i{0}; i < MAX_SIZE; i++) {
        if (bs[i]) {
            std::cout << i << std::endl;
        }
    }
}