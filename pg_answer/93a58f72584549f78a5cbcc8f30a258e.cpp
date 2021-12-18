#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int n;
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        int d;
        do {
            std::cin >> d;
            q.push(d);
        } while (std::cin.get() == ' ');
        while (!q.empty()) {
            std::cout << q.top();
            q.pop();
            std::cout << " \n"[q.empty()];
        }
    }
}