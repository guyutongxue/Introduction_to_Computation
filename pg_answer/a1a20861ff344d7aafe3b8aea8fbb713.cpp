#include <iostream>
#include <map>
#include <string>

// clang-format off
const std::map<std::string, int> DISTANCE{
    {"Mercury", 36},
    {"Venus", 67},
    {"Earth", 93},
    {"Mars", 141},
    {"Jupiter", 483},
    {"Saturn", 886},
    {"Uranus", 1782},
    {"Neptune", 2793}
};
const std::map<std::string, double> GRAVITY{
    {"Mercury", 0.27},
    {"Venus", 0.86},
    {"Earth", 1.00},
    {"Mars", 0.37},
    {"Jupiter", 2.64},
    {"Saturn", 1.17},
    {"Uranus", 0.92},
    {"Neptune", 1.44}
};
// clang-format on

int main() {
    std::string name, destination;
    int weight, speed;
    std::cin >> name >> weight >> speed >> destination;
    std::cout << name << std::endl;
    std::cout << weight << std::endl;
    std::cout << destination << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << weight * GRAVITY.at(destination) << std::endl;
    if (speed == 0) {
        std::cout << "Sorry, he can never get there = =..." << std::endl;
    } else {
        std::cout << std::abs(DISTANCE.at(destination) - DISTANCE.at("Earth")) * 1'000'000.0 / speed
                  << std::endl;
    }
}