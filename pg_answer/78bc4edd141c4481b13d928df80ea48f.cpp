#include <iostream>

int main() {
    int h, u, d;
    std::cin >> h >> u >> d;
    int day{0}, height{0};
    while (true) {
        day++;
        height += u;
        if (height >= h) break;
        height -= d;
    }
    std::cout << day << std::endl;
}