#include <cstring>
#include <iostream>
bool a[502][502]{};
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int cmd, x1, y1, x2, y2;
        std::cin >> cmd >> x1 >> y1 >> x2 >> y2;
        x1++;
        y1++;
        if (cmd == 1) {
            for (int i{x1}; i <= x2; i++) {
                for (int j{y1}; j <= y2; j++) {
                    if (!a[i][j]) {
                        std::cout << "No" << std::endl;
                        goto nextLoop;
                    }
                }
            }
            std::cout << "Yes" << std::endl;
        } else {
            for (int i{x1}; i <= x2; i++) {
                for (int j{y1}; j <= y2; j++) {
                    a[i][j] = true;
                }
            }
        }
    nextLoop:;
    }
}