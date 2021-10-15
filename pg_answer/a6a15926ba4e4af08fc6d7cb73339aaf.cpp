#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int m;
    std::cin >> m;
    std::vector<int> a[26];
    for (int i = 0; i < m; i++) {
        int id;
        std::string s;
        std::cin >> id >> s;
        for (auto i : s) {
            a[i - 'A'].push_back(id);
        }
    }
    auto p{std::max_element(std::begin(a), std::end(a), [](auto&& x, auto&& y){
        return x.size() < y.size();
    })};
    std::cout << char('A' + (p - a)) << std::endl << p->size() << std::endl;
    for (auto i : *p) {
        std::cout << i << std::endl;
    }
}