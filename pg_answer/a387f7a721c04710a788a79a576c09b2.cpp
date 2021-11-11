#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string str;
        std::cin >> str;
        char base{'\0'};
        int cnt{0};
        for (auto c : str) {
            if (c == base) {
                cnt++;
            } else {
                if (cnt) std::cout << cnt << base;
                base = c;
                cnt = 1;
            }
        }
        std::cout << cnt << base << std::endl;
    }
}