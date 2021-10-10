#include <iostream>
#include <algorithm>

auto addBigInt(const std::string& a, const std::string& b) {
    std::string result;
    int sum{0};
    for (unsigned i{0}; i < a.length() || i < b.length(); i++) {
        if (i < a.length()) {
            sum += *(a.begin() + i) - '0';
        }
        if (i < b.length()) {
            sum += *(b.begin() + i) - '0';
        }
        result.push_back(sum % 2 + '0');
        sum /= 2;
    }
    if (sum) {
        result.push_back(sum + '0');
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        std::string c(addBigInt(a, b));
        std::reverse(c.begin(), c.end());
        std::cout << c << std::endl;
    }
}