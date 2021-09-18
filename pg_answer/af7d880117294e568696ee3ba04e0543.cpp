#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string line;
    std::getline(std::cin, line);

    auto spaceNum{std::count(line.begin(), line.end(), ' ')};

    std::istringstream iss(line);
    std::vector<std::string> words{""};
    while (iss >> words.back()) {
        words.push_back("");
    }
    words.pop_back();

    auto wordNum{words.size() - 1};
    int avgSpaceNum, remainSpaceNum;
    if (wordNum == 0) {
        avgSpaceNum = 0;
        remainSpaceNum = spaceNum;
    } else {
        avgSpaceNum = spaceNum / wordNum;
        remainSpaceNum = spaceNum % wordNum;
    }

    for (unsigned i{0}; i < wordNum; i++) {
        std::cout << words[i];
        std::cout << std::string(avgSpaceNum, ' ');
    }
    std::cout << words.back();
    std::cout << std::string(remainSpaceNum, ' ') << std::endl;
}