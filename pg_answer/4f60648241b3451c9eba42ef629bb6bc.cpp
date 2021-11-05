#include <string>
#include <iostream>

int t[10000010]{};
int transfer(char x) {
    if (x <= '9') return x - '0';
    if (x <= 'C') return 2;
    if (x <= 'F') return 3;
    if (x <= 'I') return 4;
    if (x <= 'L') return 5;
    if (x <= 'O') return 6;
    if (x <= 'S') return 7;
    if (x <= 'V') return 8;
    if (x <= 'Y') return 9;
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i{0}; i < n; i++) {
        std::string s;
        std::getline(std::cin, s);
        int num{0};
        for (auto c : s) {
            if (c == '-') continue;
            (num *= 10) += transfer(c);
        }
        if (num >= 0) t[num]++;
    }
    bool isEmpty{true};
    for (int i{0}; i <= 9999999; i++) {
        if (t[i] >= 2) {
            isEmpty = false;
            std::cout.fill('0');
            std::cout.width(3);
            std::cout << i / 10000 << "-";
            std::cout.width(4);
            std::cout << i % 10000 << " " << t[i] << std::endl;
        }
    }
    if (isEmpty) {
        std::cout << "No duplicates." << std::endl;
    }
}