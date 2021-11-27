#include <cstring>
#include <algorithm>
#include <cstdio>

bool m[100][100][26]{};
int g[100][100]{};
char target[100];

struct Gene {
    char s, l, r;
};
Gene norm[50];

int main() {
    int n;
    std::scanf("%d", &n);

    for (int i{0}; i < n; ++i) {
        std::scanf(" %c%c%c", &norm[i].s, &norm[i].l, &norm[i].r);
        norm[i].s -= 'A';
        norm[i].l -= 'A';
        norm[i].r -= 'A';
    }

    std::scanf("%s", target);
    int len{std::strlen(target)};

    for (int i{0}; i < len; i++) {
        target[i] -= 'A';
        for (int ss{0}; ss < 26; ss++) {
            m[i][i][ss] = target[i] == ss;
        }
        g[i][i] = target[i] == 18;
    }

    for (int r{1}; r <= len; r++) {
        for (int i{0}; i < len - r; i++) {
            int j{i + r};
            for (int k{i}; k < j; k++) {
                for (int ss{0}; ss < 26; ss++) {
                    for (int ns{0}; ns < n; ns++) {
                        if (norm[ns].s == ss) {
                            if (m[i][k][norm[ns].l] && m[k + 1][j][norm[ns].r]) {
                                m[i][j][ss] = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (m[i][j][18]) {
                g[i][j] = 1;
            } else {
                int temp{101};
                for (int k = i; k < j; k++) {
                    if (g[i][k] && g[k + 1][j]) {
                        temp = std::min(temp,  g[i][k] + g[k + 1][j]);
                    }
                }
                if (temp != 101) g[i][j] = temp;
            }
        }
    }

    if (!g[0][len - 1])
        std::puts("-1");
    else
        std::printf("%d\n", g[0][len - 1]);
}