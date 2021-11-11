#include <iostream>

bool judge(int a, int b) {
    if (a < b) std::swap(a, b);
    if (a / b >= 2 || a == b) return true;
    return !judge(b, a - b);
}

int main() {
    int a, b;
    while (std::cin >> a >> b, a) {
        std::cout << (judge(a, b) ? "win" : "lose") << std::endl;
    }
}