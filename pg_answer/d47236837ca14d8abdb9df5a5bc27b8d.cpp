#include <iostream>
#include <utility>
#include <array>

namespace details {

template<int... Vals>
constexpr std::array<int, sizeof...(Vals)> save_impl(std::integer_sequence<int, Vals...>) {
    return { (Vals * Vals * Vals)... };
}
template<int N>
constexpr auto save() {
    return save_impl(std::make_integer_sequence<int, N>{});
}

}

constexpr auto cube{details::save<101>()};

int main() {
    int n;
    std::cin >> n;
    for (int i{6}; i <= n; i++) {
        for (int j{2}; j <= i; j++) {
            for (int k{j}; k <= i; k++) {
                for (int l{k}; l <= i; l++) {
                    if (cube[l] + cube[j] + cube[k] == cube[i]) {
                        std::cout << "Cube = " << i << 
                            ", Triple = (" << j << "," << k << "," << l << ")\n";
                    }
                }
            }
        }
    }
}