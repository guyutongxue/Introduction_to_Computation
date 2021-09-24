#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int d;
        std::cin >> d;
        double bikeTime{27 + 23 + d / 3.0};
        double walkTime{d / 1.2};
        if (walkTime < bikeTime) {
            std::cout << "Walk" << std::endl;
        } else if (walkTime > bikeTime) {
            std::cout << "Bike" << std::endl;
        } else {
            std::cout << "All" << std::endl;
        }
    }
}