#include <iostream>
#include <string>
int main() {
    std::string s;
    std::cin >> s;
    for (auto& i : s) {
        std::cout << i << std::endl;
    }
}