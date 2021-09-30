#include <iostream>
#include <cstdint>


int main() {
    const uint32_t target{0b111'111'111'0};

    auto getMask{[&](int i) -> uint32_t {
        int h{i / 100};
        int d{(i - h * 100) / 10};
        int u{i % 10};
        return (1 << h) | (1 << d) | (1 << u);
    }};

    for (int i{123}; i < 987; i++) {
        if ((getMask(i) | getMask(i * 2) | getMask(i * 3)) == target) {
            std::cout << i << " " << i * 2 << " " << i * 3 << std::endl;
        }
    }
}