#include <array>
#include <cstring>
#include <iostream>
#include <limits>

const int MAX{std::numeric_limits<int>::max()};

struct Point {
    int x;
    int y;
};
Point point[16];
int n;  // 点的数量

// 计算能围住 point[i], point[j] 两点的最小矩形面积
int getSquare(int i, int j) {
    int deltaX = std::abs(point[i].x - point[j].x);
    int deltaY = std::abs(point[i].y - point[j].y);
    // 如果两点位于同一直线上，则该方向长度应为 1
    if (deltaX == 0) deltaX = 1;
    if (deltaY == 0) deltaY = 1;
    return deltaX * deltaY;
}

// **点集的表示法**
// 由于点的数量不超过 15 个，所以可以用一个数的二进制位来表示点集。
// 比如 0b01101 表示编号为 0, 2, 3 的点构成的点集。
// 随后，可以用位运算来判断一个点是否在点集中：
// 比如，判断 2 号点是否在点集 0b01101 中，可以用 (0b01101 & (1 << 2)) != 0

// canCover[i][j] 表示覆盖编号为 i 和 j（i < j）的点的最小矩形能够围住的点集。
//
// 1------+
// |   4  |
// | 8    |
// |  6   |
// +------2
// 例：上图中，canCover[1][2] = 0b10101110 = (1<<8)|(1<<6)|(1<<4)|(1<<2)|(1<<1)
//
int canCover[16][16];

// 深度优先搜索时用到的“记忆化”数组。
// mem[i] 表示围住点集 i 所需要的最小矩形面积和。
// 若该值尚未计算，则用 -1 表示。
int mem[0xffff];

// 深度优先搜索时用到的递归函数。
// dfs(i) 计算围住点集 i 所需要的最小矩形面积和。
int dfs(unsigned remain) {
    // 若计算过，则直接返回结果。
    if (mem[remain] != -1) return mem[remain];
    // 若点集为空集，则返回 0。
    if (remain == 0) return 0;

    int result{MAX};
    // 从所有点中挑出两个点（编号为 i, j）
    for (int i{0}; i < n; i++) {
        for (int j{i + 1}; j < n; j++) {
            // 如果从当前点集中去掉它们俩得到一个新的点集 newRemain...
            unsigned newRemain = remain & (~canCover[i][j]);
            if (newRemain != remain) {
                // ...那么考虑用一个最小矩形围住这两个点，
                // 然后递归地计算围起新点集的最小矩形面积和，最后加起来。
                // 如果这种覆盖方法更好，则更新结果
                result = std::min(result, dfs(newRemain) + getSquare(i, j));
            }
        }
    }
    // 更新“记忆化”数组的值，供下次使用
    return mem[remain] = result;
}

int main() {
    while (std::cin >> n, n) {
        for (int i{0}; i < n; i++) {
            std::cin >> point[i].x >> point[i].y;
        }
        // 计算所有 canCover[i][j] 的值（描述见上）
        for (int i{0}; i < n; i++) {
            for (int j{i + 1}; j < n; j++) {
                // 记录覆盖编号为 i, j 的点的最小矩形位置
                int xBegin{std::min(point[i].x, point[j].x)};
                int xEnd{std::max(point[i].x, point[j].x)};
                int yBegin{std::min(point[i].y, point[j].y)};
                int yEnd{std::max(point[i].y, point[j].y)};

                // 遍历每一个点。如果这个点落在最小矩形内，则
                // canCover[i][j] 的对应二进制位设置为 1
                canCover[i][j] = 0;
                for (int k{0}; k < n; k++) {
                    if (point[k].x >= xBegin && point[k].x <= xEnd && point[k].y >= yBegin &&
                        point[k].y <= yEnd) {
                        canCover[i][j] |= 1 << k;
                    }
                }
            }
        }

        // 将“记忆化”数组清空为“尚未计算”的值 -1
        std::fill(std::begin(mem), std::end(mem), -1);

        // 最终要计算的结果是覆盖所有点的最小矩形面积和。
        // 代表“所有点”的点集，也就是 0b11...1，位数为 n，
        // 这个值等于 (1 << n) - 1。
        std::cout << dfs((1 << n) - 1) << std::endl;
    }
}