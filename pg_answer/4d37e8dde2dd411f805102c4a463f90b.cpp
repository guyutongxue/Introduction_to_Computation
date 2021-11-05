#include <iostream>
#include <algorithm>
#include <deque>

int main() {
    int n;
    while (std::cin >> n, n) {
        std::deque<int> a(n), b(n);
        for (int i{0}; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i{0}; i < n; i++) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int sum{0};
        while (a.size()) {
            if (a.back() > b.back()) {
                a.pop_back();
                b.pop_back();
                sum++;
            } else if (a.front() > b.front()) {
                a.pop_front();
                b.pop_front();
                sum++;
            } else {
                if (a.front() < b.back())
                    sum--;
                else if (a.front() > b.back())
                    sum++;
                a.pop_front();
                b.pop_back();
            }
        }
        std::cout << sum * 200 << std::endl;
    }
}