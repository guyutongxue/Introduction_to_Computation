#include <iostream>
int main() {
    std::cout.setf(std::ios::fixed), std::cout.precision(5);
    double sum{};
    double a[10015]{};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    double ave{sum / n};
    double mean{};
    for (int i = 0; i < n; i++) {
        mean += (a[i] - ave) * (a[i] - ave);
    }
    mean /= n;
    std::cout << ave << " " << mean << std::endl;
}