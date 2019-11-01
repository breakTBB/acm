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

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

const int N = 2e5 + 10;

struct node {
    int l, r, mx;
}sgt[N << 2];
char op[10];
int n, m, le, ri;

void pushup(int id) {
    sgt[id].mx = max(sgt[lc].mx, sgt[rc].mx);
}
void build(int id, int l, int r) {
    sgt[id].l = l, sgt[id].r = r;
    if (l == r) {
        sgt[id].mx = read();
        return;
    }
    build(lc, l, mid), build(rc, mid + 1, r), pushup(id);
}
void update(int id, int pos, int val) {
    if (sgt[id].l == sgt[id].r) {
        sgt[id].mx = val;
        return;
    }
    if (pos <= mid) update(lc, pos, val);
    else update(rc, pos, val);
    pushup(id);
}
int query(int id, int ql, int qr) {
    if (sgt[id].l > qr || sgt[id].r < ql) return -inf;
    if (ql <= sgt[id].l && sgt[id].r <= qr) return sgt[id].mx;
    if (qr <= mid) return query(lc, ql, qr);
    else if (ql > mid) return query(rc, ql, qr);
    else return max(query(lc, ql, mid), query(rc, mid + 1, qr));
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        build(1, 1, n);
        rep(i, 1, m) {
            scanf("%s%d%d", op, &le, &ri);
            if (op[0] == 'Q') {
                printf("%d\n", query(1, le, ri));
            } else {
                update(1, le, ri);
            }
        }
    }
}