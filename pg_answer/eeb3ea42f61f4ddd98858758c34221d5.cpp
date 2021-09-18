#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int counted{0};
    while (n--) {
        std::string name;
        double temperature;
        int cough;
        std::cin >> name >> temperature >> cough;
        if (temperature >= 37.5 && cough == 1) {
            std::cout << name << std::endl;
            counted++;
        }
    }
    std::cout << counted << std::endl;
}