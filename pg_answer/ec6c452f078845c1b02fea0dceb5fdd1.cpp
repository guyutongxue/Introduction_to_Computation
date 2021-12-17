#include <iostream>
#include <list>
#include <algorithm>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::list<int> l;

    bool dup{false};
    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        if (x == l.back()) {
            l.pop_back();
            dup = true;
        } else if (dup) {
            l.pop_back();
            dup = false;
        }
        l.push_back(x);
    }
    if (dup) {
        l.pop_back();
    }

    bool isFirst{true};
    for (auto i : l) {
        if (isFirst) {
            isFirst = false;
        } else {
            std::cout << " ";
        }
        std::cout << i;
    }
    std::cout << std::endl;
}