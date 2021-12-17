#include <iostream>
#include <list>
#include <string>

struct Student {
    std::string no;
    std::string name;
    char gender;
    int age;
    double score;
    std::string address;
};

std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.no >> s.name >> s.gender >> s.age >> s.score >> s.address;
    return is;
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.no << ' ' << s.name << ' ' << s.gender << ' ' << s.age << ' ' << s.score << ' ' << s.address;
    return os;
}

int main() {
    std::list<Student> l;
    Student s;
    while (std::cin >> s) {
        l.push_front(s);
    }
    for (auto& i : l) {
        std::cout << i << std::endl;
    }
}