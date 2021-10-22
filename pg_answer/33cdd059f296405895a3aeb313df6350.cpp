#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

struct Bracket {
    int left;
    int right;
    bool operator<(const Bracket& b) const {
        return right - left == b.right - b.left ? left < b.left : right - left < b.right - b.left;
    }
};
int main() {
    std::stack<int> s;
    std::vector<Bracket> brackets;
    std::string str;
    std::cin >> str;
    for (int i{0}; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(i);
        }
        if (str[i] == ')') {
            if (s.empty()) {
                std::cout << "mismatch" << std::endl;
                std::exit(0);
            }
            brackets.push_back({s.top(), i});
            s.pop();
        }
    }
    if (!s.empty()) {
        std::cout << "mismatch" << std::endl;
        std::exit(0);
    }
    std::sort(brackets.begin(), brackets.end());
    if (brackets.size() == 0) {
        std::cout << "0,0" << std::endl;
        std::exit(0);
    }
    for (auto& i : brackets) {
        std::cout << i.left + 1 << "," << i.right + 1 << std::endl;
    }
}