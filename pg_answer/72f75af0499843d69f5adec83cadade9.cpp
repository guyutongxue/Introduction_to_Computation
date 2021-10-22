#include <iostream>

int main() {
    int n;
    std::cin >> n;
    n++;
    bool output{false};
    for (int i{18}; i >= 0; i--) {
        if (output) {
            std::cout << ((n &(1 << i)) ? 'G' : 'N');
        }
        if (n & (1 << i)) {
            output = true;
        }
    }
    std::cout << std::endl;
}