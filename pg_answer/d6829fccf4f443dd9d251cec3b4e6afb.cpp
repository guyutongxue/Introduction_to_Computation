#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i{2}; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool judge(int x) {
    if (!isPrime(x / 1000000)) return false;
    double sq = std::sqrt(x % 1000);
    if (floor(sq) != sq || sq == 0) return false;
    return std::to_string(x).find("13") == std::string::npos;
}
int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> v(n - m + 1);
    std::iota(v.begin(), v.end(), m);
    std::cout << std::count_if(v.begin(), v.end(), judge) << std::endl;
}