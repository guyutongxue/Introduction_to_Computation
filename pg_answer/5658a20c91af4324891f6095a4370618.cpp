#include <iostream>
#include <string>
#include <algorithm>

std::string operator+(std::string a, std::string b) {
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
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
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::string sum("0");
    while (n--) {
        std::string a;
        std::cin >> a;
        sum = sum + a;
    }
    std::cout << sum << std::endl;
}