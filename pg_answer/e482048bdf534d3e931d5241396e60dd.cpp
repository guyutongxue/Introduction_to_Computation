#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
struct Pipe {
    T value;
    Pipe(T value = T{}) : value{value} {}
    template <typename F>
    Pipe operator|(F&& f) const {
        return f(value);
    }
    operator T() const {
        return value;
    }
};

int reverse(int x) {
    std::string s{std::to_string(x)};
    std::reverse(s.begin(), s.end());
    return std::stoi(s);
}

auto add(int x) {
    return [=](int y) {
        std::cout << x << '+' << y << '=' << x + y << std::endl;
        return x + y;
    };
}

bool validate(int x) {
    return x == reverse(x);
}

int main() {
    Pipe<int> n;
    std::cin >> n.value;
    int i{0};
    for (; i < 7; i++) {
        if ((n = n | reverse | add(n)) | validate) break;
    }
    std::cout << (i == 7 ? 'N' : 'Y') << std::endl;
}