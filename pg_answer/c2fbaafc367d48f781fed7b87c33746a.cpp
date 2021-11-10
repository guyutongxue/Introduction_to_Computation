#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    int n, m;
    std::cin >> n;
    while (n--) {
        int x;
        std::cin >> x;
        q.push(x);
    }
    std::cin >> m;
    while (m--) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd[0] == 'E') {
            if (q.empty()) {
                std::cout << "NULL" << std::endl;
            } else {
                std::cout << q.top() << std::endl;
                q.pop();
            }
        } else {
            int x;
            std::cin >> x;
            q.push(x);
        }
    }
}