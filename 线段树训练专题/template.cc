//线段树维护区间增加（减少），区间最大值，区间最小值，区间和 

#include<bits/stdc++.h>

//宏命令替换常量和左右儿子标记，以及当前线段树节点表示的[l,r]的mid值 

#define lc (p<<1)
#define rc (p<<1|1)
#define mid (T[p].l+T[p].r>>1)
#define N 100005

using namespace std;

//线段树的储存以及其它变量的复制 
struct Node { int l, r, lz, sum; }T[N << 2];
int n, m, a[N];

//向上合并 
inline void pushup(int p) {
    T[p].sum = T[lc].sum + T[rc].sum + (a[T[lc].r] != a[T[rc].l]);
}


inline void build(int p, int l, int r) {
    T[p].l = l, T[p].r = r;
    if (l == r) { T[p].sum = 1; return; }
    build(lc, l, mid), build(rc, mid + 1, r);
    pushup(p);
}

inline void update(int p, int ql, int qr, int v) {
    if (T[p].l > qr || T[p].r < ql)return;
    if (ql <= T[p].l && T[p].r <= qr) { pushnow(p, v);return; }
    if (qr <= mid)update(lc, ql, qr, v);
    else if (ql > mid)update(rc, ql, qr, v);
    else update(lc, ql, mid, v), update(rc, mid + 1, qr, v);
    pushup(p);
}

inline int query_sum(int p, int ql, int qr) {
    if (T[p].l > qr || T[p].r < ql)return 0;

    if (ql <= T[p].l && T[p].r <= qr)return T[p].sum;
    if (qr <= mid)return query_sum(lc, ql, qr);
    if (ql > mid)return query_sum(rc, ql, qr);
    return query_sum(lc, ql, mid) + query_sum(rc, mid + 1, qr);
}

//读入优化函数 
inline int read() {
    int ans = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-')w = -1;ch = getchar(); }
    while (isdigit(ch))ans = (ans << 3) + (ans << 1) + (ch ^ 48), ch = getchar();
    return ans * w;
}
int main() { return 0; }