#include <algorithm>
#include <iostream>
#include <vector>

struct Bill {
    int s;
    int t;
    int w;
    bool operator<(const Bill& b) const {
        return t < b.t;
    }
};
int dp[200020];

int main() {
    int n;
    std::cin >> n;
    std::vector<Bill> a(n);
    std::vector<int> times;  // Discretization
    for (auto& i : a) {
        std::cin >> i.s >> i.t >> i.w;
        times.push_back(i.s);
        times.push_back(i.t);
    }
    std::sort(a.begin(), a.end());
    std::sort(times.begin(), times.end());
    times.erase(std::unique(times.begin(), times.end()), times.end());
    for (auto& i : a) {
        i.s = std::lower_bound(times.begin(), times.end(), i.s) - times.begin();
        i.t = std::lower_bound(times.begin(), times.end(), i.t) - times.begin();
    }
    int p{0};
    for (auto& i : a) {
        while (p < i.t) {
            p++;
            dp[p] = dp[p - 1];
        }
        dp[p] = std::max({dp[p], dp[p - 1], dp[i.s] + i.w});
    }
    std::cout << dp[a.back().t] << std::endl;
}