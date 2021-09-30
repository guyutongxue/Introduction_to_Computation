#include <iostream>
#include <map>

int sumOfBit(int x) {
    int sum{0};
    do {
        sum += x % 10;
    } while (x /= 10);
    return sum;
}

int main() {
    int n, m, k;
    char comma;
    std::cin >> m >> comma >> n >> comma >> k;
    std::multimap<int, int> mm;
    for (int i{m + 1}; i < n; i++) {
        int sum{sumOfBit(i)};
        if (sum % k == 0) {
            mm.emplace(sum, i);
        }
    }
    int lastSum{-1};
    for (auto& i : mm) {
        if (lastSum != -1) {
            if (i.first != lastSum) {
                std::cout << '\n';
            } else {
                std::cout << ',';
            }
        }
        std::cout << i.second;
        lastSum = i.first;
    }
}