#include <algorithm>
#include <iostream>
#include <numeric>

bool used[100]{};
int a[100]{};
int n;
int cnt;
bool dfs(int len, int start, int sum, int step) {
    if (step > cnt) return true;
    if (sum == len) {
        return dfs(len, 1, 0, step + 1);
    }
    int failed{0};
    for (int i{start}; i <= n; i++) {
        if (!used[i] && sum + a[i] <= len && failed != a[i]) {
            used[i] = true;
            if (dfs(len, i + 1, sum + a[i], step)) {
                return true;
            }
            used[i] = false;
            failed = a[i];
            if (sum == 0 || sum + a[i] == len) return false;
        }
    }
    return false;
}

int main() {
    while (std::cin >> n, n) {
        std::fill(std::begin(used), std::end(used), 0);
        std::fill(std::begin(a), std::end(a), 0);
        for (int i{0}; i < n; i++) {
            std::cin >> a[i];
        }
        int max = *std::max_element(a, a + n);
        int sum = std::accumulate(a, a + n, 0);
        std::sort(a, a + n, [](int a, int b) { return a > b; });
        for (int len{max}; len <= sum; len++) {
            if (sum % len == 0) {
                cnt = sum / len;
                if (dfs(len, 0, 0, 1)) {
                    std::cout << len << std::endl;
                    break;
                }
            }
        }
    }
}