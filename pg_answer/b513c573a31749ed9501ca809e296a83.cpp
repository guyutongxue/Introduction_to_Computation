#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int to_num(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else {
        return c - 'A' + 26;
    }
}

char from_num(int i) {
    if (i >= 0 && i <= 25) {
        return i + 'a';
    } else {
        return i - 26 + 'A';
    }
}

// char encode_char(char src, char key) {
//     int x{to_num(key)}, y{to_num(src)};
//     return from_num((x + y) % 52);
// }

char decode_char(char result, char key) {
    int x{to_num(key)}, z{to_num(result)};
    return from_num((z - x + 52) % 52);
}

std::string decode(const std::string& result, std::string key) {
    while (key.length() < result.length()) {
        key += key;
    }
    std::string src(result);
    std::transform(result.begin(), result.end(), key.begin(), src.begin(), decode_char);
    return src;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::stack<std::pair<int, int>> operations;
    std::vector<std::string> strs(n);
    while (m--) {
        int key, src;
        std::cin >> key >> src;
        operations.push({key - 1, src - 1});
    }
    for (auto& i : strs) {
        std::cin >> i;
    }

    while (!operations.empty()) {
        auto op{operations.top()};
        operations.pop();
        auto key{op.first}, src{op.second};
        strs[src] = decode(strs[src], strs[key]);
    }

    for (const auto& i : strs) {
        std::cout << i << std::endl;
    }
}