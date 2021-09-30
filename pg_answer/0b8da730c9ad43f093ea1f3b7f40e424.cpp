#include <iostream>


int sumOfFactor(int x) {
    constexpr int MAX{100001};
    static int saved[MAX]{};
    if (x < MAX && saved[x] != 0) {
        return saved[x];
    }
    int sum{1};
    for (int i{2}; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;
            if (i * i != x) {
                sum += x / i;
            }
        }
    }
    if (x < MAX) {
        saved[x] = sum;
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        int sf{sumOfFactor(i)};
        if (sf > i && sf < n && sumOfFactor(sf) == i) {
            std::cout << i << " " << sf << std::endl;
        }   
    }
}