#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> mentioned[101]{};

    for (int i{0}; i < n; i++) {
        int x;
        std::cin >> x;
        std::cin.ignore();
        int delim{std::cin.get()};
        while ((delim = std::cin.get()) != '\n') {
            int mentionee;
            std::cin >> mentionee;
            mentioned[mentionee].push_back(x);
        }
    }
    auto maximum{std::max_element(mentioned, mentioned + 101,
                                  [](auto a, auto b) { return a.size() < b.size(); })};
    std::cout << maximum - mentioned << std::endl;
    std::sort(maximum->begin(), maximum->end());
    maximum->erase(std::unique(maximum->begin(), maximum->end()), maximum->end());
    bool isFirst{true};
    for (auto i : *maximum) {
        std::cout << " " + isFirst << i;
        isFirst = false;
    }
}