#include <algorithm>
#include <iostream>

struct Pillar {
    int h;
    int no;
};
Pillar p[20002];

int find(int l, int r) {
    if (l == r) return p[l].h;
    if (l > r) return 0;
    Pillar min{*std::min_element(
        p + l, p + r + 1, [](auto&& a, auto&& b) { return a.h == b.h ? a.no < b.no : a.h < b.h; })};
    return std::max({min.h * (r - l + 1), find(l, min.no - 1), find(min.no + 1, r)});
}
int main() {
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        std::cin >> p[i].h;
        p[i].no = i;
    }
    std::cout << find(1, n) << std::endl;
}