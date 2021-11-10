#include <iostream>

int a[100002]{};
bool done[100002]{};
int main() {
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
    }
    int day{0};
    for (int i{1}; i <= n; i++) {
        if (done[i]) continue;
        done[i] = true;
        for (int j{a[i]}; !done[j] && j <= n; j = a[j]) {
            done[j] = true;
        }
        day++;
    }
    std::cout << day << std::endl;
}