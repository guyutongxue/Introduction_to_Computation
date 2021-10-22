#include <iostream>
#include <array>
#include <string>
#include <algorithm>

namespace details {

constexpr bool isPrimeLoop(int i, int k) {
    return (k * k > i) ? true : (i % k == 0) ? false : isPrimeLoop(i, k + 1);
}

constexpr bool isPrime(int i) {
    return i <= 1 ? false : isPrimeLoop(i, 2);
}

template<int... Vals>
constexpr std::array<bool, sizeof...(Vals)> save_impl(std::integer_sequence<int, Vals...>) {
    return { (isPrime(Vals))... };
}
template<int N>
constexpr auto save() {
    return save_impl(std::make_integer_sequence<int, N>{});
}

}

constexpr auto prime{details::save<10000>()};

int main() {
    int m, n;
    std::cin >> m >> n;

    bool isFirst{true};
    for (int i{m}; i <= n; ++i) {
        if (prime[i]) {
            std::string rev(std::to_string(i));
            std::reverse(rev.begin(), rev.end());
            if (prime[std::stoi(rev)]) {
                if (isFirst) {
                    isFirst = false;
                } else {
                    std::cout << ",";
                }
                std::cout << i;
            }
        }
    }
    if (isFirst) {
        std::cout << "No";
    }
    std::cout << std::endl;
}