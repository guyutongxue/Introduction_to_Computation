#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        std::string filtered;
        std::copy_if(s.begin(), s.end(), std::back_inserter(filtered), [](char c) {
            return std::isupper(c) || std::islower(c);
        });
        std::string reversed(filtered.rbegin(), filtered.rend());
        std::cout << std::boolalpha << (filtered == reversed) << std::endl;
    }
}