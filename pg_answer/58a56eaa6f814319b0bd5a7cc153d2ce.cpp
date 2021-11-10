#include <algorithm>
#include <iostream>

int main() {
    int r, n;
    while (std::cin >> r >> n, r != -1) {
        int a[1200]{};
        for (int i{0}; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(&a[0], &a[n]);
        int ans{0};
        int pos{0};
        while (pos <= n) {
            int k{pos};
            while (k <= n && a[k] - a[pos] <= r) {
                k++;
            }
            if (a[k] - a[pos] > r) k--;
            pos = k;
            while (k <= n && a[k] - a[pos] <= r) {
                k++;
            }
            pos = k;
            ans++;
        }

        std::cout << ans << std::endl;
    }
}