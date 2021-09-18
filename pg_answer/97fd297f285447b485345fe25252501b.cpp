#include <iostream>
int main() {
    bool a[151]{};

    for (int i{1}; i <= 150; i++) {
        for (int j{1}; j <= 150; j++) {
            a[j] ^= !(j % i);
        }
    }
    int cnt{0};
    bool firstOutput{true};
    for (int i{1}; i < 151; i++) {
        if (a[i]) {
            std::cout << " N" + firstOutput << i;
            firstOutput = false;
            cnt++;
        }
    }
    std::cout << std::endl << cnt << std::endl;
}