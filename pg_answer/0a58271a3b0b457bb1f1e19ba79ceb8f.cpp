#include <algorithm>
#include <iostream>
#include <map>
#include <set>

std::map<std::string, std::set<int>> userBought;
std::map<int, std::map<int, int>> relations;

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string user;
        int product;
        std::cin >> user >> product;
        userBought[user].insert(product);
    }

    for (auto& user : userBought) {
        std::set<int> userProducts = user.second;

        for (auto& product : userProducts) {
            auto& i{relations[product]};
            for (auto& j : userProducts) {
                if (j != product) {
                    i[j]++;
                }
            }
        }
    }
    int target;
    std::cin >> target;
    auto& targetMap{relations[target]};
    auto it = std::max_element(targetMap.begin(), targetMap.end(),
                               [](auto& a, auto& b) { return a.second < b.second; });
    std::cout << it->first << std::endl;
}