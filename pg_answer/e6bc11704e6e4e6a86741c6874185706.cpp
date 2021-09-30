#include <iostream>

struct Vector3 {
    int x, y, z;
};

class Vector {
    int x, y;

public:
    Vector() = default;
    Vector(int x, int y) : x(x), y(y) {}

    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector3 operator*(const Vector& v1, const Vector& v2);

    friend std::istream& operator>>(std::istream& is, Vector& v);
};

Vector operator-(const Vector& v1, const Vector& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vector3 operator*(const Vector& v1, const Vector& v2) {
    return {0, 0, v1.x * v2.y - v1.y * v2.x};
}

std::istream& operator>>(std::istream& is, Vector& v) {
    is >> v.x >> v.y;
    return is;
}

inline bool isPositive(const Vector3 v) {
    return v.z > 0;
}

int main() {
    Vector a, b, c, d;
    while (std::cin >> a >> b >> c >> d) {
        if ((isPositive((a - b) * (c - a)) ^ isPositive((a - b) * (d - a))) ||
            (isPositive((b - c) * (a - b)) ^ isPositive((b - c) * (d - b))) ||
            (isPositive((c - d) * (a - c)) ^ isPositive((c - d) * (b - c)))) {
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
    }
}