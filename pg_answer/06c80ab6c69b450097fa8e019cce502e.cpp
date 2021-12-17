#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>

std::string dic[110];
bool used[110];
int n, ans;
std::string astr;

void dfs(const std::string& sub, int templ, const std::string& tans) {
    for (int i{0}; i < n; i++) {
        if (used[i]) continue;
        if (dic[i] == sub) {
            if (ans > templ + sub.length()) {
                ans = templ + sub.length();
                astr = tans + sub;
            }
            return;
        } else if (dic[i].length() > sub.length() && dic[i].find(sub, 0) == 0) {
            used[i] = true;
            std::string tstr = dic[i].substr(sub.length());
            dfs(tstr, templ + sub.length(), tans + sub);
            used[i] = false;
        } else if (dic[i].length() < sub.length() && sub.find(dic[i], 0) == 0) {
            used[i] = true;
            std::string tstr = sub.substr(dic[i].length());
            dfs(tstr, templ + dic[i].length(), tans + dic[i]);
            used[i] = false;
        }
    }
}

int main() {
    ans = std::numeric_limits<int>::max();
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dic[i];
    }
    std::sort(dic, dic + n);
    for (int i{1}; i < n; i++) {
        for (int j{0}; j < i; j++) {
            if (dic[i].find(dic[j], 0) == 0 && dic[i] != dic[j]) {
                used[i] = true;
                used[j] = true;
                std::string tstr =
                    dic[i].substr(dic[j].length(), dic[i].length() - dic[j].length());
                dfs(tstr, dic[j].length(), dic[j]);
                used[i] = false;
                used[j] = false;
            }
        }
    }
    std::cout << astr << std::endl;
}