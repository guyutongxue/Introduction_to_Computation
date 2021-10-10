#include <iostream>
#include <string>
int main() {
    std::string a;
    std::getline(std::cin, a);
    int uNum{}, lNum{}, dNum{};
    for (int i{0}; i < a.length(); i++) {
        if (std::isupper(a[i])) {
            uNum++;
        } else if (std::islower(a[i])) {
            lNum++;
        } else if (std::isdigit(a[i])) {
            dNum++;
        }
    }
    std::cout << uNum << " " << lNum << " " << dNum << std::endl;
}