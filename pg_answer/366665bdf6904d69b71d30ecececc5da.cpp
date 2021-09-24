#include <iostream>
#include <array>

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
    int m;
    std::cin >> m;
    for (int i{3}; i <= m / 2; i++) {
        int j{m - i};
        if (prime[i] && prime[j]) {
            std::cout << i << " " << j << std::endl;
        }
    }
}