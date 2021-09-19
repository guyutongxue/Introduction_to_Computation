#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Coord {
    int x;
    int y;
    int value;

    int operator-(const Coord& b) const {
        return std::abs(x - b.x) + std::abs(y - b.y);
    }
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<Coord> coords;
        int m, n, k;
        std::cin >> m >> n >> k;
        for (int i{1}; i <= m; i++) {
            for (int j{1}; j <= n; j++) {
                int val;
                std::cin >> val;
                if (val) coords.push_back({i, j, val});
            }
        }
        std::sort(coords.begin(), coords.end(),
                  [](const auto& a, const auto& b) { return a.value > b.value; });
        int time{coords.front().x + 1};
        int value{coords.front().value};
        for (unsigned i{1}; i < coords.size(); i++) {
            time += coords[i] - coords[i - 1] + 1;
            if (time + coords[i].x > k) break;
            value += coords[i].value;
        }
        std::cout << value << std::endl;
    }
}