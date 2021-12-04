#include <algorithm>
#include <iostream>
#include <string>

int a[1000][1000]{};
int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    for (int i{1}; i <= s1.size(); i++) {
        for (int j{1}; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                a[i][j] = a[i - 1][j - 1] + 1;
            else {
                a[i][j] = std::max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    std::cout << a[s1.size()][s2.size()] << std::endl;
}