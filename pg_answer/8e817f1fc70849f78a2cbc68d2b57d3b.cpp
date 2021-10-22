#include <algorithm>
#include <set>
#include <iostream>

int main() {
    std::set<int> a, b;
    while (true) {
        int x;
        std::cin >> x;
        a.insert(x);
        if (std::cin.get() == '\n') break;
    }
    while (true) {
        int x;
        std::cin >> x;
        b.insert(x);
        if (std::cin.get() == '\n') break;
    }
    std::set<int> c;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));
    bool isFirst{true};
    for (auto x : c) {
        if (!isFirst) {
            std::cout << ',';
        } else {
            isFirst = false;
        }
        std::cout << x;
    }
    if (isFirst) {
        std::cout << "NULL";
    }
    std::cout << std::endl;
}