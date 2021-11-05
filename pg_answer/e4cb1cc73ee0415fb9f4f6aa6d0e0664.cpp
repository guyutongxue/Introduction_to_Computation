#include <string>
#include <iostream>

int main() {
    int a[24];
    bool visited[24]{};
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        std::cin >> a[i];
    }
    int i{1}, step{1};
    visited[0] = true;
    while (i < n + 1) {
        if (visited[i]) {
            i++;
            step += 2;
            continue;
        }
        visited[i] = true;
        i += a[i];
        step += 1;
        if (i < 0) i = 0;
    }
    std::cout << step << std::endl;
}