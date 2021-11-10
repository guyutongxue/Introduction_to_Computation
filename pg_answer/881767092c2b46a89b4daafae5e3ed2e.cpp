#include <iostream>

int main() {
    int n, m;
    int s[10000]{};
    std::cin >> n >> m;
    for (int i{1}; i <= n; i++) {
        s[i] = i;
    }
    for (int i{0}; i < m; i++) {
        char cmd;
        int a, b;
        std::cin >> cmd;
        std::cin >> a >> b;
        if (cmd == 'M') {
            int setNo{s[b]};
            for (int j{1}; j <= n; j++) {
                if (s[j] == setNo) s[j] = s[a];
            }
            s[b] = s[a];
        } else {
            std::cout << (s[a] == s[b] ? "Yes" : "No") << std::endl;
        }
    }
}