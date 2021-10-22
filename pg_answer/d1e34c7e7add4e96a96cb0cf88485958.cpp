#include <iostream>
#include <string>

bool isAbbr(const std::string& a, const std::string& b) {
    if (a.size() == 0) {
        return true;
    }
    auto p{b.find(a[0])};
    if (p != std::string::npos) {
        return isAbbr(a.substr(1), b.substr(p + 1));
    } else {
        return false;
    }
}
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        std::string abbr, word;
        std::getline(std::cin, abbr, ':');
        std::getline(std::cin, word);
        std::cout << (isAbbr(abbr, word) && abbr.size() < word.size() ? "YES" : "NO") << std::endl;
    }
}