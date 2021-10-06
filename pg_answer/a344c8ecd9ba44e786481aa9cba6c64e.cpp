#include <iostream>
#include <algorithm>

int main() {
    int delta[1010]{};
    int number{0};
    while (true) {
        int x;
        std::cin >> x;
        delta[x]++;
        number++;
        int delim{std::cin.get()};
        if (delim == '\n') break;
    }
    std::cout << number << ' ';
    while (true) {
        int x;
        std::cin >> x;
        delta[x]--;
        int delim{std::cin.get()};
        if (delim == '\n') break;
    }
    int total{0}, answer{0};
    for (auto i : delta) {
        total += i;
        answer = std::max(answer, total);
    }
    std::cout << answer << std::endl;
}