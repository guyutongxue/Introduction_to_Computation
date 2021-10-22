#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>

void caesar(std::string& s) {
    for (auto& c : s) {
        if (std::isupper(c)) {
            c += 3;
            if (c > 'Z') c -= 26;
        } else if (std::islower(c)) {
            c += 3;
            if (c > 'z') c -= 26;
        }
    }
}

void reverse(std::string& s) {
    std::reverse(s.begin(), s.end());
}

void reverseCap(std::string& s) {
    for (auto& c : s) {
        if (std::isupper(c)) {
            c = std::tolower(c);
        } else if (std::islower(c)) {
            c = std::toupper(c);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (auto& i : v) {
        std::cin >> i;
        reverseCap(i);
        reverse(i);
        caesar(i);
    }
    std::sort(v.begin(), v.end());
    for (auto& i : v) {
        std::cout << i << std::endl;
    }
}