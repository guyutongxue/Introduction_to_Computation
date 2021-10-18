#include <algorithm>
#include <array>
#include <iostream>
#include <string>
const std::array<std::string, 12> MONTH_NAMES{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const std::array<std::string, 7> WEEK_NAMES{"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// Zeller Formula
int calcWeek(int year, int month, int day) {
    if (month <= 2) year--, month += 12;
    int c{year / 100};
    int y{year % 100};
    int week{y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1};
    week %= 7;
    return week < 0 ? week + 7 : week;
}
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        int d{0}, m{0}, y{0};
        int curlen{0};
        for (int j{0}; j <= s.length(); j++) {
            if (s[j] == '-' || s[j] == '/' || s[j] == '\0') {
                if (curlen == 2) {
                    d = std::stoi(s.substr(j - 2, 2));
                }
                if (curlen == 3) {
                    std::string month{s.substr(j - 3, 3)};
                    auto p{std::find(MONTH_NAMES.begin(), MONTH_NAMES.end(), month)};
                    m = p - MONTH_NAMES.begin() + 1;
                }
                if (curlen == 4) {
                    y = std::stoi(s.substr(j - 4, 4));
                }
                curlen = 0;
            } else {
                curlen++;
            }
        }
        std::cout << WEEK_NAMES[calcWeek(y, m, d)] << '.' << std::endl;
    }
}