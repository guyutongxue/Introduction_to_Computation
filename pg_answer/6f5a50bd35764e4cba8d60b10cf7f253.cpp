#include <iostream>
#include <string>

std::string str{};
int firstClose(int pos) {
    if (str[pos] != str.front()) {
        return pos;
    } else {
        int n{firstClose(pos + 1)};
        std::cout << pos << ' ' << n << std::endl;
        return firstClose(n + 1);
    }
}
int main() {
    std::cin >> str;
    firstClose(0);
}