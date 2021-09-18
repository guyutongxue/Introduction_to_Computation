#include <iostream>
#include <string>
#include <vector>

class Matrix {
private:
    int r, c;
    int* p{nullptr};

    int current_row{0}, current_col{0};
    int up_limit{1}, down_limit, left_limit{0}, right_limit;
    enum Direction { UP, DOWN, LEFT, RIGHT } direction{RIGHT};
    void next() {
        switch (direction) {
            case UP:
                if (--current_row == up_limit) {
                    direction = RIGHT;
                    up_limit++;
                }
                break;
            case DOWN:
                if (++current_row == down_limit) {
                    direction = LEFT;
                    down_limit--;
                }
                break;
            case LEFT:
                if (--current_col == left_limit) {
                    direction = UP;
                    left_limit++;
                }
                break;
            case RIGHT:
                if (++current_col == right_limit) {
                    direction = DOWN;
                    right_limit--;
                }
                break;
        }
    }

    int& operator()(int row, int col) {
        return p[row * c + col];
    }

public:
    Matrix(int rows, int columns)
        : r{rows}, c{columns}, down_limit{rows - 1}, right_limit{columns - 1} {
        p = new int[r * c]{};
    }

    ~Matrix() {
        delete[] p;
    }

    void set(int* data, int len) {
        auto& g{*this};
        for (int i = 0; i < len; i++) {
            g(current_row, current_col) = data[i];
            next();
        }
    }

    void print() {
        for (int i = 0; i < r * c; i++) {
            std::cout << p[i];
        }
        std::cout << std::endl;
    }
};

int main() {
    int r, c;
    std::string s;
    std::cin >> r >> c;
    Matrix m(r, c);

    std::cin.ignore();
    std::getline(std::cin, s);
    std::vector<int> v;
    for (auto& c : s) {
        if (c == ' ') {
            v.push_back(0), v.push_back(0);
        } else {
            int r{c - 'A' + 1};
            v.push_back(r / 10), v.push_back(r % 10);
        }
    }
    m.set(v.data(), v.size());
    m.print();
}