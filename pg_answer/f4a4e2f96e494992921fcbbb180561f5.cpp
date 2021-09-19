#include <algorithm>
#include <iostream>
#include <vector>

// a, b: The smallest; c, d: The largest
// method1: ad>, a<，ac>，a<, ab> time spent: 2a+b+c+d
// method2: ab>, a<, cd>，b<，ab> time spent: a+3b+d
int solve(const int* nums, int len) {
    int totalTime{0};
    while (len > 3) {
        totalTime += std::min(2 * nums[0] + nums[len - 2] + nums[len - 1],
                              nums[0] + 2 * nums[1] + nums[len - 1]);
        len -= 2;
    }
    if (len == 1) {
        totalTime += nums[0];
    } else if (len == 2) {
        totalTime += nums[1];
    } else {
        totalTime += nums[0] + nums[1] + nums[2];
    }
    return totalTime;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a[1002];
        for (int i{0}; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a, a + n);
        std::cout << solve(a, n) << std::endl;
    }
}