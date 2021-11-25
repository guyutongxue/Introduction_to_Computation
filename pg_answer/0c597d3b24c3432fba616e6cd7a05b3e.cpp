#include <iostream>

void moveDisk(int n, char src, char dest, char trans) {
    if (n == 1) {
        std::cout << src << "->" << dest << std::endl;
        return;
    }
    moveDisk(n - 1, src, trans, dest);
    std::cout << src << "->" << dest << std::endl;
    moveDisk(n - 1, trans, dest, src);
}
int main() {
    int n;
    std::cin >> n;
    moveDisk(n, 'A', 'C', 'B');
}
