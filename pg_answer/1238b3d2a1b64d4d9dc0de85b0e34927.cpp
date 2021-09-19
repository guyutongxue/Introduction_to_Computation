#include <iostream>
#include <utility>
#include <array>

template<int N>
struct Fib {
    static constexpr const int val{Fib<N-1>::val + Fib<N-2>::val};
};
template<>
struct Fib<0> {
    static constexpr const int val{0};
};
template<>
struct Fib<1> {
    static constexpr const int val{1};
};

template<int... Vals>
constexpr std::array<int, sizeof...(Vals)> save_impl(std::integer_sequence<int, Vals...>) {
    return { Fib<Vals>::val... };
}
template<int N>
constexpr auto save() {
    return save_impl(std::make_integer_sequence<int, N>{});
}

const auto fib{save<21>()};

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int i;
        std::cin >> i;
        std::cout << fib[i] << std::endl;
    }
}