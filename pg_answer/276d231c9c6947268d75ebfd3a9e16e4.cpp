#include <iostream>
#include <vector>
#include <algorithm>

enum Status {
    HEALTHY,    // A healthy status, nothing happened.
    ILL,        // Has been inflected.
    DANGEROUS,  // Will be ill next day.
    RECOVERED   // Healthy and won't be inflected again.
};

struct Student {
    Status status{HEALTHY};
    std::vector<Student*> friends;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Student> students(n + 1);
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        students[x].friends.push_back(&students[y]);
        students[y].friends.push_back(&students[x]);
    }
    
    int root;
    std::cin >> root;
    students[root].status = ILL;

    int cnt{1};
    int days;
    for (days = 0; cnt; days++) {
        for (const auto& j : students) {
            if (j.status == ILL) {
                for (auto& k : j.friends) {
                    if (k->status == HEALTHY) k->status = DANGEROUS;
                }
            }
        }
        for (auto& j : students) {
            switch (j.status) {
                case HEALTHY:
                case RECOVERED: break;
                case ILL: {
                    j.status = RECOVERED;
                    cnt--;
                    break;
                }
                case DANGEROUS: {
                    j.status = ILL;
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == 2'000'000'000) {
            std::cout << -1 << std::endl;
            std::exit(0);
        }
    }
    std::cout << days << std::endl;
}