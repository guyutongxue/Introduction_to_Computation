#include <algorithm>
#include <iostream>
#include <vector>

int n;
struct Bill {
    int s;
    int t;
    int c;
    bool operator<(const Bill& b) const {
        return t == b.t ? s < b.s : t < b.t;
    }
};
std::int64_t save[100002];
int main() {
    std::cin >> n;
    std::vector<Bill> tax(n);
    for (auto& i : tax) {
        std::cin >> i.s >> i.t >> i.c;
    }
    std::stable_sort(tax.begin(), tax.end());
    std::int64_t max = save[0] = tax[0].c;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int l = 0, r = j, mid;
        while (r - l > 1) {
            mid = (r + l) / 2;
            if (tax[mid].t <= tax[i].s) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (tax[l].t > tax[i].s && tax[l + 1].t > tax[i].s) {
            save[i] = tax[i].c;
        } else {
            if (tax[l + 1].t <= tax[i].s) {
                save[i] = tax[i].c + save[l + 1];
            } else {
                save[i] = tax[i].c + save[l];
            }
        }
        if (save[i] < save[i - 1]) save[i] = save[i - 1];
        if (save[i] > max) max = save[i];
    }
    std::cout << max << std::endl;
}