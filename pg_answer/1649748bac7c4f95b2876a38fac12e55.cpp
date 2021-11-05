#include <algorithm>
#include <iostream>

bool covered[100005]{};
int main() {
    int n;
    std::cin >> n;
    int inf{100005}, sup{1};
    for (int i{0}; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (inf > a) inf = a;
        if (sup < b) sup = b;
        std::fill(covered + a, covered + b, true);
    }
    bool need = false;
    for (int i{inf}; i < sup; i++) {
        if (!covered[i]) {
            need = true;
            for (int j{i}; j <= sup; j++) {
                if (covered[j]) {
                    std::cout << i << ' ' << j << std::endl;
                    break;
                }
                covered[j] = true;
            }
        }
    }
    if (!need) {
        std::cout << "Not Needed" << std::endl;
    }
}