#include <iostream>
#include <vector>

int ans;
std::vector<int> v;

void dfs(int i, int m) {
    if (m == 0) {
        ans++;
        return;
    }
    if (i == v.size()) return;
    
    dfs(i + 1, m - v[i]);
    dfs(i + 1, m);
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        v.push_back(n);
        if (std::cin.get() == '\n') break;
    }
    int m;
    while (std::cin >> m, m != 0) {
        ans = 0;
        dfs(0, m);
        std::cout << ans << std::endl;
    }
}