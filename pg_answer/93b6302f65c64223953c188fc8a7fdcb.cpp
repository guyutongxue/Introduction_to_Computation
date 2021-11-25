#include <iostream>
#include <numeric>

int main() {
    double w[12]{};
    for (auto& i : w) {
        std::cin >> i;
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << '$' << std::accumulate(w, w + 12, 0.0) / 12.0 << std::endl;
}