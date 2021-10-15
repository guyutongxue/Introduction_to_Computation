#include <iostream>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::string r(s);
    std::reverse(r.begin(), r.end());
    std::cout << (r == s ? "yes" : "no") << std::endl;
}