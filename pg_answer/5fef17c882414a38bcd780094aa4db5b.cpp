#include <iostream>
#include <algorithm>

int main() {
    int a[5][5];
    int maxnum[5];
    for (int i{0}; i < 5; i++) {
        for (int j{0}; j < 5; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i{0}; i < 5; i++) {
        maxnum[i] = std::max_element(a[i], a[i] + 5) - a[i];
    }
    
    for (int i{0}; i < 5; i++) {
        bool notSaddle{false};
        for (int j{0}; j < 5; j++) {
            if (a[i][maxnum[i]] > a[j][maxnum[i]]){
                notSaddle = true;
                break;
            }
        }
        if (!notSaddle) {
            std::cout << i + 1 << ' ' << maxnum[i] + 1 << ' ' << a[i][maxnum[i]] << std::endl;
            std::exit(0);
        }
    }
    std::cout << "not found" << std::endl;
}