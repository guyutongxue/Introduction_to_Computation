#include <iostream>

int main() {
    int p, e, i, d;
    int caseNo{0};
    while (std::cin >> p >> e >> i >> d, p >= 0) {
        caseNo++;
        int k{d + 1};
        while ((k - p) % 23) {
            k++;
        }
        while ((k - e) % 28) {
            k += 23;
        }
        while ((k - i) % 33) {
            k += 23 * 28;
        }
        std::cout << "Case " << caseNo << ": the next triple peak occurs in " << k - d << " days."
                  << std::endl;
    }
}