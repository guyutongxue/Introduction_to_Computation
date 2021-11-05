#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int cnt[26]{};
    std::string line;
    while (std::getline(std::cin, line)) {
        for (auto c : line) {
            if (std::isupper(c)) {
                cnt[c - 'A']++;
            }
        }
    }
    int max{*std::max_element(cnt, cnt + 26)};
    for (int i{max}; i >= 1; i--) {
        std::string l{"#"};
        for (int j{0}; j < 26; j++) {
            if (cnt[j] >= i) {
                l += " *";
            } else {
                l += "  ";
            }
        }
        l.erase(l.find_last_not_of(' ') + 1);
        std::cout << l << std::endl;
    }
    std::cout << "# A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << std::endl;
}