#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    std::string reversed(s.rbegin(), s.rend());
    std::cout << (reversed == s) << std::endl;
}