#include <iostream>
#include <array>
#include <functional>
#include <algorithm>
#include <sstream>

int count(int x) {
    int cnt{0};
    if (x & 1) cnt++;
    if (x & 2) cnt++;
    if (x & 4) cnt++;
    if (x & 8) cnt++;
    return cnt;
}

void print(int x) {
    std::ostringstream oss;
    if (x & 1) oss << " 1";
    if (x & 2) oss << " 2";
    if (x & 4) oss << " 3";
    if (x & 8) oss << " 4";
    std::cout << oss.str().substr(1) << std::endl;
}

int main() {
    std::array<int, 4> lang{{}};
    // clang-format off
    std::array<std::function<bool()>, 5> validators{{
        [&](){ return count(lang[0]) == 2 && count(lang[1]) == 2 && count(lang[2]) == 2 && count(lang[3]) == 1; },
        [&](){
            for (int i{0}; i < 4; ++i) {
                int cnt{0};
                for (auto j : lang) {
                    if (j & (1 << i)) cnt++;
                }
                if (cnt >= 3) return true;
            }
            return false;
        },
        [&](){ return (lang[0] & 8) && !(lang[3] & 8) && !(lang[1] & 2); },
        [&](){ return !(lang[0] & lang[2]) && !(lang[2] & lang[3]) && (lang[1] & lang[2]); },
        [&](){ return ((lang[0] & 12) != 12) && ((lang[1] & 12) != 12) && ((lang[2] & 12) != 12) && ((lang[3] & 12) != 12); }
    }};
    // clang-format on
    for (lang[0] = 0; lang[0] < 16; lang[0]++) {
        for (lang[1] = 0; lang[1] < 16; lang[1]++) {
            for (lang[2] = 0; lang[2] < 16; lang[2]++) {
                for (lang[3] = 0; lang[3] < 16; lang[3]++) {
                    if (std::all_of(validators.begin(), validators.end(),
                                    [](auto& v) { return v(); })) {
                        for (auto l : lang) {
                            print(l);
                        }
                    }
                }
            }
        }
    }
}