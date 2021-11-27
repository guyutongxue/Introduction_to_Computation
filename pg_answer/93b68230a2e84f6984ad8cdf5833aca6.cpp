#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string pattern, word;
    while (true) {
        char c;
        std::cin.get(c);
        if (c == '\n') break;
        else if (c == '*') pattern += ".*";
        else if (c == '?') pattern += ".";
        else pattern += c;
    }
    std::getline(std::cin, word);
    std::regex re(pattern);
    std::cout << (std::regex_match(word, re) ? "" : "not ") << "matched" << std::endl;
}