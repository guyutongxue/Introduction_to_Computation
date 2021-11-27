#include <string>
#include <iostream>

double calculate() {
    std::string str;
    std::cin >> str;
    switch (str[0]) {
        case '+': {
            double a{calculate()};
            return a + calculate();
        }
        case '-': {
            double a{calculate()};
            return a - calculate();
        }
        case '*': {
            double a{calculate()};
            return a * calculate();
        }
        case '/': {
            double a{calculate()};
            return a / calculate();
        }
        default: return std::stod(str);
    }
}
int main() {
    std::cout.setf(std::ios::fixed);
    std::cout << calculate() << std::endl;
}