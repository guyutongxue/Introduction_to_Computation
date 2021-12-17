#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int target;
std::string src;
int n;
bool cutpoint[7];
std::vector<int> res;
bool isError, isReject;
int min;

void analyse() {
    std::vector<int> frag;
    int start{0};
    for (int i{1}; i <= n; i++) {
        if (cutpoint[i]) {
            frag.emplace_back(std::stoi(src.substr(start, i - start)));
            start = i;
        }
    }
    frag.emplace_back(std::stoi(src.substr(start)));
    int sum = std::accumulate(frag.begin(), frag.end(), 0);
    if (sum <= target) {
        if (sum > min) {
            isError = false;
            isReject = false;
            min = sum;
            res = frag;
        } else if (sum == min) {
            isReject = true;
        }
    }
}

void cut(int pos) {
    if (pos > n) {
        analyse();
        return;
    }
    cutpoint[pos] = false;
    cut(pos + 1);
    cutpoint[pos] = true;
    cut(pos + 1);
}

int main() {
    while (std::cin >> target >> src, target != 0 || src != "0") {
        if (target == std::stoi(src)) {
            std::cout << src << " " << src << std::endl;
            continue;
        }
        n = src.length() - 1;
        isError = true;
        isReject = false;
        min = -1;
        cut(1);
        if (isError) {
            std::cout << "error" << std::endl;
        } else if (isReject) {
            std::cout << "rejected" << std::endl;
        } else {
            std::cout << min << " ";
            for (unsigned i{0u}; i < res.size(); i++) {
                std::cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
            }
        }
    }
}