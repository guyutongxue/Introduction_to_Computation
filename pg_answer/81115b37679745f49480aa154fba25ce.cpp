#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int n1{0}, n2{0};
    std::vector<int> a;
    for (int i{0}; i < n; i++) {
        int time;
        std::cin >> time;
        if (time <= 60) n1++;
        if (time > 60 && time < 180) {
            a.push_back(time);
        }
    }
    std::sort(a.begin(), a.end());
    if (n1 >= 12) {
        std::cout << 12 << std::endl;
    } else {
        int t{10 * n1 + 60};
        int num{n1};
        for (auto i : a) {
            if (t >= i && t <= 170) {
                t += 10;
                num++;
            }
            if (t < i && i <= 170) {
                t = i + 10;
                num++;
            }
            if (t > 170 || i > 170) {
                break;
            }
        }
        std::cout << num << std::endl;
    }
}