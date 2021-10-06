#include <iostream>
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int m, s{60};
        std::cin >> m;
        for (int i{0}; i < m; ++i) {
            int a;
            std::cin >> a;
            if (a < s) {
                if (a + 3 > s)
                    s = a;
                else
                    s -= 3;
            }
        }
        std::cout << s << std::endl;
    }
}