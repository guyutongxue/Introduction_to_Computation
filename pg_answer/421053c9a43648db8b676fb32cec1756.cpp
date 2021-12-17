#include <algorithm>
#include <iostream>
#include <string>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i{2}; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    std::string a;
    int sum[101]{};
    std::cin >> a;
    std::transform(a.begin(), a.end(), sum,
                   [&](char x) { return std::count(a.begin(), a.end(), x); });
    std::sort(sum, sum + a.size());
    auto delta{sum[a.size() - 1] - sum[0]};
    if (isPrime(delta)) {
        std::cout << "Lucky Word\n" << delta << std::endl;
    } else {
        std::cout << "No Answer\n0" << std::endl;
    }
}