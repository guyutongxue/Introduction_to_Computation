#include <iostream>
#include <string>
#include <stack>

using namespace std::literals;

int main() {
    std::stack<std::string> s;
    std::string str;
    while (std::cin >> str) {
        s.push(str);
    }
    bool isFirst{true};
    while (!s.empty()) {
        if (isFirst) {
            std::cout << s.top();
            isFirst = false;
        } else {
            std::cout << " " << s.top();
        }
        s.pop();
    }
}