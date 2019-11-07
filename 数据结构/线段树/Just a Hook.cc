#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}
const int N = 1e5 + 10;
struct SegmentTree {
    int l, r, v, lz;
}sgt[N << 2];
void pushup(int id) {
    sgt[id].v = sgt[lc].v + sgt[rc].v;
}
void pushnow(int id, int val) {
    sgt[id].v = (sgt[id].r - sgt[id].l + 1) * val;
    sgt[id].lz = val;
}
void pushdown(int id) {
    if (sgt[id].lz == 0) return;
    pushnow(lc, sgt[id].lz), pushnow(rc, sgt[id].lz), sgt[id].lz = 0;
}
void build(int id, int l, int r) {
    sgt[id].l = l, sgt[id].r = r, sgt[id].v = 1, sgt[id].lz = 0;
    if (l == r) return;
    build(lc, l, mid), build(rc, mid + 1, r), pushup(id);
}
void update(int id, int ql, int qr, int val) {
    if (sgt[id].l > qr || sgt[id].r < ql) return;
    if (ql <= sgt[id].l && sgt[id].r <= qr) {
        pushnow(id, val);
        return;
    }
    pushdown(id);
    if (qr <= mid) update(lc, ql, qr, val);
    else if (ql > mid) update(rc, ql, qr, val);
    else update(lc, ql, mid, val), update(rc, mid + 1, qr, val);
    pushup(id);
}
int query(int id, int ql, int qr) {
    if (sgt[id].l > qr || sgt[id].r < ql) return 0;
    if (ql <= sgt[id].l && sgt[id].r <= qr) return sgt[id].v;
    pushdown(id);
    if (qr <= mid) return query(lc, ql, qr);
    else if (ql > mid) return query(rc, ql, qr);
    else return query(lc, ql, mid) + query(rc, mid + 1, qr);
}
int main() {
    int T = read();
    int kase = 1;
    while(T--) {
        int n = read(), q = read();
        build(1, 1, n);
        while(q--) {
            int x = read(), y = read(), z = read();
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase++, query(1, 1, n));
    }
}