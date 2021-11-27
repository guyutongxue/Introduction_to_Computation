#include <iostream>
#include <string>

int main() {
    int n;
    while (std::cin >> n) {
        if (n <= 9) {
            std::cout << n << std::endl;
            continue;
        } else if (n <= 189) {
            int t{10 + (n - 10) / 2};
            if (n % 2 == 0) {
                std::cout << t / 10 << std::endl;
            } else {
                std::cout << t % 10 << std::endl;
            }
        } else if (n <= 2889) {
            int t{100 + (n - 190) / 3};
            int i{(n - 190) % 3};
            std::cout << std::to_string(t)[i] << std::endl;
        } else {
            int t{1000 + (n - 2890) / 4};
            int i{(n - 2890) % 4};
            std::cout << std::to_string(t)[i] << std::endl;
        }
    }
}