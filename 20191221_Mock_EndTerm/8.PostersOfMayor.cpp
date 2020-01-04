// 我不会这道题，别问。

#ifdef OLD

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
void swap(pp &x, pp &y){
\1
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
void add(int p, int L, int R, int z, int x, int y){
\1
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
int fv(int p, int L, int R, int x, int y){
\1
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

int main(){
\1
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

#else

#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n;
int vis[maxn<<3],sum[maxn<<4];
int li[maxn*2],ri[maxn*2],lsh[maxn<<2];
void pushdown(int rt){
    sum[rt<<1]=sum[rt];
    sum[rt<<1|1]=sum[rt];
    sum[rt]=-1;
}
void update(int L,int R,int C,int l,int r,int rt){
    if(L<=l&&r<=R){
        sum[rt]=C;
        return ;
    }
    if(sum[rt]!=-1)
        pushdown(rt);
    int m=(l+r)>>1;
    if(m>=R) update(L,R,C,l,m,rt<<1);
    else if(L>m) update(L,R,C,m+1,r,rt<<1|1);
    else update(L,m,C,l,m,rt<<1),update(m+1,R,C,m+1,r,rt<<1|1);
}
int ans;
void query(int l,int r,int rt){
        if(!vis[sum[rt]]&&sum[rt]!=-1){
            ans++;
            vis[sum[rt]]=1;
        return;
        }
    if(l==r)return;
    if(sum[rt]!=-1)
        pushdown(rt);
    int m=(l+r)>>1;
    query(l,m,rt<<1);
    query(m+1,r,rt<<1|1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(sum,-1,sizeof(sum));
        memset(vis,0,sizeof(vis));
        int tot=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&li[i],&ri[i]);
            lsh[tot++]=li[i];
            lsh[tot++]=ri[i];
        }
        sort(lsh,lsh+tot);
        int mm=unique(lsh,lsh+tot)-lsh;
        int tt=mm;
        for(int i=1;i<tt;i++){
            if(lsh[i]-lsh[i-1]>1)
                lsh[mm++]=lsh[i-1]+1;
        }
        sort(lsh,lsh+mm);
        for(int i=0;i<n;i++){
            int x=lower_bound(lsh,lsh+mm,li[i])-lsh;
            int y=lower_bound(lsh,lsh+mm,ri[i])-lsh;
            update(x,y,i,0,mm-1,1);
        }
        ans=0;
        query(0,mm-1,1);
        printf("%d\n",ans);
    }
}

#endif