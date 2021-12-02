#include <iostream>
#include <string>

int n;

void search(const std::string& s, int open, int lCnt, int rCnt) {
    if (lCnt == n && rCnt == n) {
        std::cout << s << std::endl;
        return;
    }

    if (lCnt < n) {
        search(s + "(", open + 1, lCnt + 1, rCnt);
    }
    if (open > 0 && rCnt < n) {
        search(s + ")", open - 1, lCnt, rCnt + 1);
    }
}

int main() {
    std::cin >> n;
    search("", 0, 0, 0);
}