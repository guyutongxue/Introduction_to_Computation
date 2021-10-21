#include <algorithm>
#include <iostream>

struct Pin {
    int no;
    int prev;
    int next;
    double rate() const {
        return 1. * next / prev;
    }
};

int main() {
    int n;
    std::cin >> n;
    Pin pins[102]{};
    for (int i{0}; i < n; i++) {
        int no, prev, next;
        std::cin >> no >> prev >> next;
        pins[i] = {no, prev, next};
    }
    std::sort(pins, pins + n, [](const Pin& a, const Pin& b) { return a.rate() < b.rate(); });
    double diff[102]{};
    for (int i{1}; i < n; i++) {
        diff[i] = pins[i].rate() - pins[i - 1].rate();
    }
    auto ptr{std::max_element(diff + 1, diff + n)};
    int aNum{ptr - diff};
    std::cout << n - aNum << std::endl;
    for (int i{aNum}; i < n; i++) {
        std::cout << pins[i].no << std::endl;
    }
    std::cout << aNum << std::endl;
    for (int i{0}; i < aNum; i++) {
        std::cout << pins[i].no << std::endl;
    }
}