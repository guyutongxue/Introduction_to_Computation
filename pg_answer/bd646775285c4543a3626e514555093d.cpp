#include <algorithm>
#include <iostream>
#include <string>

constexpr int MAX_LEN{401};
int a1[MAX_LEN]{}, a2[MAX_LEN]{};

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::fill(a1, a1 + MAX_LEN, 0);
        std::fill(a2, a2 + MAX_LEN, 0);
        std::string str1, str2;
        std::cin >> str1 >> str2;
        for (int i{0}; i < str1.length(); i++) {
            a1[i] = *(str1.rbegin() + i) - '0';
        }
        for (int i{0}; i < str2.length(); i++) {
            a2[i] = *(str2.rbegin() + i) - '0';
        }

        for (int i{0}; i < MAX_LEN; i++) {
            a2[i] += a1[i];
            if (a2[i] >= 10) {
                a2[i] -= 10;
                a2[i + 1]++;
            }
        }

        {
            std::reverse_iterator<int*> rbegin{a2 + MAX_LEN}, rend{a2};
            auto i{std::find_if(rbegin, rend, [](int x) { return x != 0; })};

            if (i == rend) {
                std::cout << 0 << std::endl;
            } else {
                while (i != rend) {
                    std::cout << *i++;
                }
            }
            std::cout << std::endl;
        }
    }
}