#include <algorithm>
#include <iostream>
#include <string>

int findSub(const std::string& dest, const std::string& ptrn) {
    for (int i = 0; i < dest.size() - ptrn.size(); i++) {
        if (dest.substr(i, ptrn.size()) == ptrn) {
            return i + ptrn.size() - 1;
        }
    }
    return -1;
}
int main() {
    std::string s, s1, s2;
    std::getline(std::cin, s, ',');
    std::getline(std::cin, s1, ',');
    std::getline(std::cin, s2);
    int a{findSub(s, s1)};
    std::reverse(s.begin(), s.end());
    std::reverse(s2.begin(), s2.end());
    int b{findSub(s, s2)};
    if (a == -1 || b == -1 || a + b > s.size() - 2) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << s.size() - 2 - (a + b) << std::endl;
    }
}