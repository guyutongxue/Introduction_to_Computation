#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string wideS;
int ans{0}, k;
void search(std::size_t pos) {
    if (pos == wideS.size() - 1) {
        std::string result;
        std::copy_if(wideS.begin(), wideS.end(), std::back_inserter(result),
                     [](char x) { return x != ' '; });
        if (std::count(result.begin(), result.end(), '*') != k) return;
        std::vector<int> factors;
        std::size_t it{0};
        while (it < result.size()) {
            std::size_t len;
            factors.emplace_back(std::stoi(result.substr(it), &len));
            it += len + 1;
        }
        ans = std::max(ans, std::accumulate(factors.begin(), factors.end(), 1,
                                            [](int a, int b) { return a * b; }));
        return;
    }
    wideS[pos + 1] = ' ';
    search(pos + 2);
    wideS[pos + 1] = '*';
    search(pos + 2);
}

int main() {
    std::string s;
    std::cin >> s >> k;
    for (auto c : s) {
        wideS += c;
        wideS += ' ';
    }
    wideS.pop_back();
    search(0);
    std::cout << ans << std::endl;
}