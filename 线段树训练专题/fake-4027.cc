#include <bits/stdc++.h>

#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)

typedef long long ll;

using namespace std;

const int maxn = 1e5 + 10;
int n, m;

struct Node {
	int l, r;
	ll sum;
}t[maxn << 2];

void pushup(int id) {
	t[id].sum = t[lc].sum + t[rc].sum;
}

void build(int id, int l, int r) {
	t[id].l = l; t[id].r = r; t[id].sum = 0;
	if (l == r) {
		cin >> t[id].sum;
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(id);
}

void update(int id, int ql, int qr) {
	if (t[id].l > qr || t[id].r < ql) return;
	if (t[id].sum == t[id].r - t[id].l + 1) return;
	if (t[id].l == t[id].r) {
		t[id].sum = sqrt(t[id].sum);
		return;
	}
	if (qr <= mid) update(lc, ql, qr);
	else if (ql > mid) update(rc, ql, qr);
	else update(lc, ql, mid), update(rc, mid + 1, qr);
	pushup(id);
}

int query(int id, int ql, int qr) {
	if (t[id].l > qr || t[id].r < ql) return 0;
	if (ql <= t[id].l && t[id].r <= qr) return t[id].sum;
	if (qr <= mid) return query(lc, ql, qr);
	else if (ql > mid) return query(rc, ql, qr);
	else return query(lc, ql, mid) + query(rc, mid + 1, qr);
}

int main() {
	ios::sync_with_stdio(false);
	int cas = 0;
	while (cin >> n) {
		memset(t, 0, sizeof t);
		build(1, 1, n);
		cout << "Case #" << ++cas << ":\n";
		cin >> m;
		while (m--) {
			int op, le, ri;
			cin >> op >> le >> ri;
			if (le > ri) swap(le, ri);
			if (op) {
				cout << query(1, le, ri) << endl;
			} else {
				update(1, le, ri);
			}
		}
		cout << endl;
	}
}