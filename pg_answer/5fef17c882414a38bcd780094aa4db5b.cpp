#include <algorithm>
#include <iostream>

int main() {
    int a[5][5];
    int maxnum[5];
    for (auto& i : a) {
        for (auto& j : i) {
            std::cin >> j;
        }
    }
    std::transform(a, a + 5, maxnum,
                   [](int(&line)[5]) -> int { return std::max_element(line, line + 5) - line; });

    for (int i{0}; i < 5; i++) {
        bool notSaddle{false};
        for (int j{0}; j < 5; j++) {
            if (a[i][maxnum[i]] > a[j][maxnum[i]]) {
                notSaddle = true;
                break;
            }
        }
        if (!notSaddle) {
            std::cout << i + 1 << ' ' << maxnum[i] + 1 << ' ' << a[i][maxnum[i]] << std::endl;
            std::exit(0);
        }
    }
    std::cout << "not found" << std::endl;
}