#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;
    std::string reversed(n);
    std::reverse(reversed.begin(), reversed.end());
    if (n == reversed) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}