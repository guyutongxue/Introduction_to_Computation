#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int n;
    std::cin >> n;
    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        pq.push(x);
    }
    int total{0};
    while (pq.size() > 1) {
        int a, b;
        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();
        pq.push(a + b);
        total += a + b;
    }
    std::cout << total << std::endl;
}