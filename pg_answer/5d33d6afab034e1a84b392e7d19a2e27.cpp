#include <iostream>
#include <regex>
int main() {
    std::string num;
    std::cout.setf(std::ios::fixed);
    while (std::cin >> num, num != "q") {
        std::regex r("[^0-9.+-]");
        num = std::regex_replace(num, r, "e");
        std::cout << std::stod(num) << std::endl;
    }
}