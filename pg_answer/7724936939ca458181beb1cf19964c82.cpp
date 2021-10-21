#include <set>
#include <iostream>
#include <array>

constexpr bool isPrimeLoop(int i, int k) {
    return (k * k > i) ? true : (i % k == 0) ? false : isPrimeLoop(i, k + 1);
}

constexpr bool isPrime(int i) {
    return isPrimeLoop(i, 2);
}

constexpr int nextPrime(int k) {
    return isPrime(k) ? k : nextPrime(k + 1);
}

constexpr int getPrimeLoop(int i, int k) {
    return (i == 0) ? k : getPrimeLoop(i - 1, nextPrime(k + 1));
}

constexpr int getPrime(int i) {
    return getPrimeLoop(i, 2);
}

template<int... Vals>
constexpr std::array<int, sizeof...(Vals)> save_impl(std::integer_sequence<int, Vals...>) {
    return { (getPrime(Vals))... };
}
template<int N>
constexpr auto save() {
    return save_impl(std::make_integer_sequence<int, N>{});
}

constexpr auto prime{save<100>()};

int main() {
    int x, y;
    char comma;
    std::cin >> x >> comma >> y;
    std::set<int> px, py;
    for (int i{0}; prime[i] < x; i++){
        if (x % prime[i] == 0) {
            px.insert(prime[i]);
        }
    }
    for (int i{0}; prime[i] < y; i++){
        if (y % prime[i] == 0) {
            py.insert(prime[i]);
        }
    }
    if (px == py) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}