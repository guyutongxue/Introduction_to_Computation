#include <iostream>

int n, k;

bool judge(int num, int times) {
    if (!times) {
        if (num)
            return true;
        else
            return false;
    }
    if ((num - k) % n) return false;
    return judge((n - 1) * (num / n), times - 1);
}

int main() {
    std::cin >> n >> k;
    int i{0};
    while (!judge(++i, n)) {
    }
    std::cout << i << std::endl;
}
