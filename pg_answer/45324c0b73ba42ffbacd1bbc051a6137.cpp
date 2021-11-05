#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    char from[11][11], to[11][11];
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cin >> from[i][j];
        }
    }
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cin >> to[i][j];
        }
    }

    // clang-format off
    std::function<bool()> translations[]{
        [&](){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (from[i][j] != to[j][n - 1 - i]) return false;
                }
            }
            return true;
        },
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (from[i][j] != to[n - 1 - j][i]) return false;
                }
            }
            return true;
        },
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (from[i][j] != to[n - 1 - i][n - 1 - j]) return false;
                }
            }
            return true;
        },
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (from[i][j] != to[i][j]) return false;
                }
            }
            return true;
        }
    };
    // clang-format on

    std::cout << std::find_if(translations, translations + 4, [](auto& f) { return f(); }) -
                     translations + 1
              << std::endl;
}