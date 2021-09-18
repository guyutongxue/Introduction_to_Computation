#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std::literals;

int main() {
    std::vector<std::string> ans;
    int n;
    std::cin >> n;
    if (n % 3 == 0) ans.push_back(" 3");
    if (n % 5 == 0) ans.push_back(" 5");
    if (n % 7 == 0) ans.push_back(" 7");
    if (ans.size() == 0)
        std::cout << "n" << std::endl;
    else
        std::cout << std::accumulate(ans.begin(), ans.end(), ""s).substr(1) << std::endl;
}