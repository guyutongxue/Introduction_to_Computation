#include <algorithm>
#include <iostream>
#include <vector>
struct Coord {
    int x;
    int y;
    bool isMaximal{true};
    bool operator<(const Coord& rhs) const {
        return this->x == rhs.x ? this->y < rhs.y : this->x < rhs.x;
    }
};

std::istream& operator>>(std::istream& in, Coord& c) {
    in >> c.x >> c.y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Coord& c) {
    out << "(" << c.x << "," << c.y << ")";
    return out;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Coord> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            if (j == i) continue;
            if (a[j].x >= a[i].x && a[j].y >= a[i].y) {
                a[i].isMaximal = false;
            }
        }
    }

    std::vector<Coord> maximals;
    std::copy_if(a.begin(), a.end(), std::back_inserter(maximals), [](const Coord& c) { return c.isMaximal; });
    std::sort(maximals.begin(), maximals.end());

    bool isFirst{true};
    for (auto& i : maximals) {
        if (isFirst) {
            isFirst = false;
        } else {
            std::cout << ",";
        }
        std::cout << i;
    }
}