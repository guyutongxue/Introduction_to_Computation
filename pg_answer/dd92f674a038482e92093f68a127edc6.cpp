#include <algorithm>
#include <iostream>
#include <numeric>

struct Patient {
    int no;
    int time;
};

int main() {
    int n;
    std::cin >> n;
    Patient a[1002];
    for (int i{0}; i < n; i++) {
        int t;
        std::cin >> t;
        a[i] = {i + 1, t};
    }
    std::sort(a, a + n, [](const Patient &a, const Patient &b) { return a.time < b.time; });
    for (int i{0}; i < n; i++) {
        std::cout << a[i].no << " \n"[i == n - 1];
    }
    int count{n};
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << std::accumulate(a, a + n, 0,
                                 [&](int a, const Patient &b) { return a + (--count) * b.time; }) *
                     1.0 / n
              << std::endl;
}