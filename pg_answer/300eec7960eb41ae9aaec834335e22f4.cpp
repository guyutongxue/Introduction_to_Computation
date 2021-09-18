#include <iostream>
bool a[202], b[202];
int main() {
    int n;
    std::cin >> n;
    int ca{0}, cb{0};
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i]) ca++;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
        if (b[i]) cb++;
    }
    if (ca != cb) {
        std::cout << "-1" << std::endl;
        std::exit(0);
    }
    int cnt{0};
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) continue;
        int j{i};
        while (a[j] != b[i]) j++;
        while (j != i) {
            std::swap(a[j], a[j - 1]);
            cnt++;
            j--;
        }
    }
    std::cout << cnt << std::endl;
}