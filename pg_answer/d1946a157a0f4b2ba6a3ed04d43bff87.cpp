#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        bool isFirst{true};
        auto print{[&](int x) {
            if (isFirst) {
                isFirst = false;
            } else {
                std::cout << " ";
            }
            std::cout << x;
        }};
        
        int k;
        std::cin >> k;
        int a[82]{};
        for (int j{0}; j < k; j++) {
            std::cin >> a[j];
        }
        if (a[0] != a[1]) {
            print(0);
        }
        for (int j{1}; j < k - 1; j++) {
            if ((a[j] - a[j - 1]) * (a[j + 1] - a[j]) < 0) {
                print(j);
            }
        }
        if (a[k - 1] != a[k - 2]) {
            print(k - 1);
        }
        std::cout << std::endl;
    }
}