#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string a;
    std::getline(std::cin, a);

    auto starNum{std::count(a.begin(), a.end(), '*')};
    auto atNum{std::count(a.begin(), a.end(), '@')};

    std::cout << "*出现了" << starNum << "次;" << std::endl;
    std::cout << "@出现了" << atNum << "次." << std::endl;
}