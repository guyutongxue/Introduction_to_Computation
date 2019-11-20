#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#define INF 1<<30
template<class T>
class Calc {
    static const int MX = 100000;
    char op[MX];
    int lch[MX], rch[MX], r ;
    T s[MX];
    bool DIV_ZERO;
    int _build(const std::string& S, int L, int R) {
        int u;
        int t = L;
        while (t <= R && (isdigit(S.at(t)) || S.at(t) == '.')) t++;
        if (t == R + 1) {
            u = r++;
            op[u] = '.';
            lch[u] = rch[u] = -1;
            s[u] = std::atof(S.substr(L, t - L).c_str());
            return u;
        }
        std::vector<int> c ;
        c.push_back(-1);
        c.push_back(-1);
        for (int i = L, p = 0; i <= R; i++) {
            if (S.at(i) == '(') p++;
            else if (S.at(i) == ')') p--;
            else if ((S.at(i) == '+' || S.at(i) == '-') && !p) c.at(0) = i;
            else if ((S.at(i) == '*' || S.at(i) == '/') && !p) c.at(1) = i;
        }
        if (c.at(0) < 0)
            c.at(0) = c.at(1);
        if (c.at(0) < 0)
            u = _build(S, L + 1, R - 1);
        else {
            u = r++;
            op[u] = S[c[0]];
            lch[u] = _build(S, L, c[0] - 1);
            rch[u] = _build(S, c[0] + 1, R);
            s[u] = -1;
        }
        return u;
    }
    T _calc(int u) {
        if (op[u] == '.') return s[u];
        T al = _calc(lch[u]), ar = _calc(rch[u]);
        switch (op[u]) {
        case '+': return al + ar;
        case '-': return al - ar;
        case '*': return al * ar;
        case '/': return (ar == 0 ? DIV_ZERO = 1 : al / ar);
        }
        //assert(false);
        return al;
    }
public:
    T solve(const std::string& s) {
        r = 0;
        DIV_ZERO = false;
        int u = _build(s, 0, (int)s.length() - 1);
        if (!DIV_ZERO)
            return _calc(u);
        else
            /// 运算过程中发生除0
            return INF;
    }
};
Calc<long long> int_calc;
Calc<long double> dbl_calc;

int main() {
    std::string expr;
    while (std::cin >> expr) {
       
        
        if (expr.find(".") == std::string::npos) {
            long long ans = int_calc.solve(expr);
            printf("%lld\n", ans);
        }
        else {
            long double ans = dbl_calc.solve(expr);
            printf("%.6f\n", (double)ans);
        }
    }
    return 0;
}