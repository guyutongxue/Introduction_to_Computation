#include <iostream>
#include <array>
#include <functional>
#include <algorithm>

int main() {
    std::array<int, 5> rank{{1, 2, 3, 4, 5}};
    // clang-format off
    std::array<std::function<bool()>, 5> validators{{
        [&](){ return (rank[1] == 2) ^ (rank[0] == 3); },
        [&](){ return (rank[1] == 2) ^ (rank[4] == 4); },
        [&](){ return (rank[2] == 1) ^ (rank[3] == 2); },
        [&](){ return (rank[2] == 5) ^ (rank[3] == 3); },
        [&](){ return (rank[4] == 4) ^ (rank[0] == 1); }
    }};
    // clang-format on
    while (std::next_permutation(rank.begin(), rank.end())) {
        for (auto& v: validators) {
            if (!v()) {
                goto next;
            }
        }
        for (auto i : rank) {
            std::cout << i << std::endl;
        }
        next:;
    }
}