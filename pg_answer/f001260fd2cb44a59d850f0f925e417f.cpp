#include <iostream>
#include <algorithm>

int main() {
    int f[1005]{};
    int w[105], v[105];
    int t, n;
    std::cin >> t >> n;
    for (int i{1}; i <= n; i++) {
        std::cin >> w[i] >> v[i];
    }
    for (int i{1}; i <= n; i++) {
        for (int j{t}; j >= w[i]; j--) {
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
        }
    }
    std::cout << f[t] << std::endl;
}