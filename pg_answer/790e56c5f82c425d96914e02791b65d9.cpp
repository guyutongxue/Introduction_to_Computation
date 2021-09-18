#include <iostream>

int main() {
    double x, m;
    std::cin >> x >> m;
    double saved{x};
    int y{1};
    while (y <= 100) {
        if (saved >= m) {
            std::cout << y << std::endl;
            std::exit(0);
        }
        saved += x *= 1.08;
        m *= 1.10;
        y++;
    }
    std::cout << "Forget it." << std::endl;
}