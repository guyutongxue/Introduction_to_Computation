#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        static int a[100002]{};
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        int ans{0};
        for (int i = 1; i <= n / 2; i++) {
            ans += a[n - i + 1] - a[i];
        }
        std::cout << ans << std::endl;
    }
}