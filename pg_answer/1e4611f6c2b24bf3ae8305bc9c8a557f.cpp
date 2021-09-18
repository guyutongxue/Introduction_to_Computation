#include <iostream>
#include <algorithm>
#include <string>

std::string operator*(std::string lhs, int rhs) {
    auto addBigInt{[](const std::string& a, const std::string& b) {
        std::string result;
        int sum{0};
        for (unsigned i{0}; i < a.length() || i < b.length(); i++) {
            if (i < a.length()) {
                sum += *(a.begin() + i) - '0';
            }
            if (i < b.length()) {
                sum += *(b.begin() + i) - '0';
            }
            result.push_back(sum % 10 + '0');
            sum /= 10;
        }
        if (sum) {
            result.push_back(sum + '0');
        }
        return result;
    }};
    std::string result{"0"};
    std::reverse(lhs.begin(), lhs.end());
    while (rhs--) {
        result = addBigInt(result, lhs);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a;
    while(std::cin >> a) {
        auto b{a.length() + 1};
        auto result{a * b == std::string(b - 1, '9')};
        std::cout << a << (result ? " is " : " is not ") << "cyclic" << std::endl;
    }
}