#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

struct Node {
    int l, r;
    int mx;
}t[maxn << 2];

void build(int id, int l, int r) {
    t[id].l = l; t[id].r = r;
    if (l == r) {
        scanf("%d", &t[id].mx);
        return;
    }
    int mid = (l + r) /2 ;
    build(id << 1, l, mid); build(id << 1 | 1, mid + 1, r);
    t[id].mx = max(t[id<< 1].mx, t[id<< 1| 1].mx);
}

void update(int id, int p, int val) {
    if (p > t[id].r || p < t[id].l) return;
    if (t[id].l = t[id].r) {
        t[id].mx = val;
        return;
    }
    int mid = (t[id].l + t[id].r) / 2;
    if (p <= mid) update(id << 1, p, val);
    else if (p > mid) update(id << 1 | 1, p, val);
    else update(id << 1, t[id].l, mid), update(id << 1 | 1, mid + 1, t[id].r);
    t[id].mx = max(t[id << 1].mx, t[id << 1 | 1].mx);
}

int query(int id, int ql, int qr) {
    if (t[id].l > qr || t[id].r < ql) return INT_MIN;
    if (ql <= t[id].l && t[id].r <= qr) return t[id].mx;
    int mid = (t[id].l + t[id].r) / 2;
    if (qr <= mid) query(id << 1, ql, mid);
    else if (ql > mid) query(id << 1 | 1, mid + 1, qr);
    else return max(query(id << 1, ql, mid), query(id << 1 | 1, mid + 1, qr));
}

int main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    while(m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'Q') {
            cout << query(1, a, b) << endl;
        } else {
            update(1, a, b);
        }
    }
}