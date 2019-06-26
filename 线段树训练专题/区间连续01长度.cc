#include <bits/stdc++.h>

using namespace std;

#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
#define N 50010

inline int read()  {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) if (c == '-') f = -1;
    while(isdigit(c)) {ret = (ret << 3) + (ret << 2) + c - '0'; c = getchar();}
    return ret * f;
}

inline void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

struct Node {
    int l, r, ms, ls, rs, lazy;
} t[N << 2];

inline void pushup(int id) {
    t[id].ls = t[lc].ls, t[id].rs = t[rc].rs;
    if (t[id].ls == t[lc].r - t[lc].l + 1) t[id].ls += t[rc].ls;
    if (t[id].rs == t[rc].r - t[rc].l + 1) t[id].rs += t[lc].rs;
    t[id].ms = max(max(t[lc].ms, t[rc].ms), t[lc].rs + t[rc].ls);
}
inline void pushnow(int id, int val) {
    t[id].ls = t[id].rs = t[id].ms = (1 - val) * (t[id].r - t[id].l + 1);
    t[id].lazy = val;
}

inline void pushdown(int id) {
    if (t[id].lazy == -1) return;
    pushnow(lc, t[id].lazy);
    pushnow(rc, t[id].lazy);
    t[id].lazy = -1;
}

inline void build(int id, int l, int r) {
    t[id].l = l, t[id].r = r, t[id].ls = t[id].rs = t[id].ms = r - l + 1;
    if (l == r) return;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(id);
}

inline void update(int id, int ql, int qr, int val) {
    if (ql <= t[id].l && t[id].r <= qr) {
        pushnow(id, val);
        return;
    }
    pushdown(id);
    
}

int main() {

}