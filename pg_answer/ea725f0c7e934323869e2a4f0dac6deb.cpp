#include <algorithm>
#include <iostream>

struct Problem {
    int score;
    int time;
    int bestResult;
    int timeSpent;
};

int main() {
    int n, t;
    std::cin >> n >> t;
    Problem p[1000]{};
    for (int i{0}; i < n; i++) {
        char comma;
        std::cin >> p[i].score >> comma >> p[i].time;
    }
    for (int i{0}; i < n; i++) {
        for (int j{i}; j < n; j++) {
            if (p[i].timeSpent + p[j].time <= t) {
                p[i].bestResult += p[j].score;
                p[i].timeSpent += p[j].time;
            } else
                break;
        }
    }
    auto bestId{std::max_element(&p[0], &p[n],
                                 [](auto& a, auto& b) {
                                     return a.bestResult == b.bestResult
                                                ? a.timeSpent > b.timeSpent
                                                : a.bestResult < b.bestResult;
                                 }) -
                &p[0]};
    std::cout << bestId + 1 << ':' << p[bestId].bestResult << ';' << p[bestId].timeSpent
              << std::endl;
}