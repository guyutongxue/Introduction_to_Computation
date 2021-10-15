#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::regex pattern("\\d+");
    std::smatch matches;

    std::sregex_iterator rbegin(std::begin(line), std::end(line), pattern), rend{};

    std::vector<int> numbers;
    std::transform(rbegin, rend, std::back_inserter(numbers),
                   [](const std::smatch& match) { return std::stoi(match.str()); });
    std::sort(numbers.begin(), numbers.end());

    bool isFirst{true};
    for (auto i : numbers) {
        if (isFirst) {
            std::cout << i;
            isFirst = false;
        } else {
            std::cout << "," << i;
        }
    }
    if (isFirst) {
        std::cout << "0" << std::endl;
    }
}