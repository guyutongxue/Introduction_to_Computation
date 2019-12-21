#include <cstdio>

#include <cstdlib>
#include <cstring>
struct pp
{
    int v, w, num;
};
pp t[20100]; //记录每一个poster的l,r,i，以便离散；
int f[80001], l[10001], r[10001];
bool twice[20001];
//f数组记录线段树，twice记录颜色是否被计算过;
void swap(pp &x, pp &y)
{
    pp t = x;
    x = y;
    y = t;
}
void sort(int x, int y) //排序；
{
    int i = x, j = y, k = t[(x + y) / 2].v;
    do
    {
        while (k < t[j].v)
            j--;
        while (k > t[i].v)
            i++;
        if (i <= j)
        {
            swap(t[j], t[i]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < y)
        sort(i, y);
    if (j > x)
        sort(x, j);
}
//结点覆盖；
void add(int p, int L, int R, int z, int x, int y)
{
    if (L == x && R == y)
    {
        f[p] = z;
        return;
    }
    int mid = (L + R) / 2;
    if (y <= mid)
        add(p * 2, L, mid, z, x, y);
    else if (x > mid)
        add(p * 2 + 1, mid + 1, R, z, x, y);
    else
    {
        add(p * 2, L, mid, z, x, mid);
        add(p * 2 + 1, mid + 1, R, z, mid + 1, y);
    }
}
//查询；
int fv(int p, int L, int R, int x, int y)
{
    if (x == L && y == R)
        return f[p];
    int mid = (L + R) / 2, u;
    if (y <= mid)
        u = fv(p * 2, L, mid, x, y);
    else if (x > mid)
        u = fv(p * 2 + 1, mid + 1, R, x, y);
    if (f[p] != 0)
        return f[p] > u ? f[p] : u;
    else
        return u;
}

int main()
{
    int c, n;
    scanf("%d", &c);
    for (int yym = 1; yym <= c; yym++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &l[i], &r[i]);
            t[(i - 1) * 2 + 1].v = l[i];
            t[(i - 1) * 2 + 1].w = 1;
            t[(i - 1) * 2 + 1].num = i;
            t[i * 2].v = r[i];
            t[i * 2].w = 2;
            t[i * 2].num = i;
        }
        sort(1, n + n);
        t[0].v = 0;
        int tot = 0;
        for (int i = 1; i <= n + n; i++)
        { //离散；
            if (t[i].v != t[i - 1].v)
                tot++;
            if (t[i].w == 1)
                l[t[i].num] = tot;
            else
                r[t[i].num] = tot;
        }
        memset(f, 0, sizeof(f));
        int p, ans = 0;
        memset(twice, true, sizeof(twice));
        for (int i = 1; i <= n; i++)
            add(1, 1, tot, i, l[i], r[i]);
        //printf("%d\n",tot);
        for (int i = 1; i <= tot; i++)
        {
            p = fv(1, 1, tot, i, i);
            if (twice[p])
            {
                twice[p] = false;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}