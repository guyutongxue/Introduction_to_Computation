#include <iostream>
#include <string>

int main() {
    int a1{}, a2{};
    int b1{}, b2{};
    int la;
    std::cin >> la;
    std::cin.ignore();
    while (la--) {
        std::string line;
        std::getline(std::cin, line);
        std::size_t pos;
        while (pos = line.find("if "), pos != std::string::npos) {
            a1++;
            line.erase(pos, 3);
        }
        while (pos = line.find("switch "), pos != std::string::npos) {
            a1++;
            line.erase(pos, 7);
        }
        while (pos = line.find("for "), pos != std::string::npos) {
            a2++;
            line.erase(pos, 4);
        }
        while (pos = line.find("while "), pos != std::string::npos) {
            a2++;
            line.erase(pos, 6);
        }
    }
    int lb;
    std::cin >> lb;
    std::cin.ignore();
    while (lb--) {
        std::string line;
        std::getline(std::cin, line);
        std::size_t pos;
        while (pos = line.find("if "), pos != std::string::npos) {
            b1++;
            line.erase(pos, 3);
        }
        while (pos = line.find("switch "), pos != std::string::npos) {
            b1++;
            line.erase(pos, 7);
        }
        while (pos = line.find("for "), pos != std::string::npos) {
            b2++;
            line.erase(pos, 4);
        }
        while (pos = line.find("while "), pos != std::string::npos) {
            b2++;
            line.erase(pos, 6);
        }
    }
    std::cout << ((a1 == b1 && a2 == b2) ? "Yes" : "No") << std::endl;
}