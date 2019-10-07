// https://vjudge.net/problem/ZOJ-1610
// Count the Colors 
// 区间染色

#include <bits/stdc++.h>

#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)

using namespace std;

const int maxn = 8e3 + 10;
int cnt = 0;

struct Node {
	int l, r, lazy;
}t[maxn << 2];

int a[maxn];
int col[maxn];
int n, last;

void pushdown(int id) {
	if (t[id].lazy != -1) t[lc].lazy = t[rc].lazy = t[id].lazy;
	t[id].lazy = -1;
}

void build(int id, int l, int r) {
	t[id].l = l; t[id].r = r; t[id].lazy = -1;
	if (l == r) return;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}

void update(int id, int ql, int qr, int val) {
	if (t[id].l > qr || t[id].r < ql) return;
	if (ql <= t[id].l && t[id].r <= qr) {
		t[id].lazy = val;
		return;
	}
	pushdown(id);
	if (qr <= mid) update(lc, ql, qr, val);
	else if (ql > mid) update(rc, ql, qr, val);
	else update(lc, ql, mid, val), update(rc, mid + 1, qr, val);
}

void query(int id, int ql, int qr) {
	if (t[id].l == t[id].r) {
		if (t[id].lazy != -1 && t[id].lazy != last) col[t[id].lazy]++;
		last = t[id].lazy;
		return;
	}
	pushdown(id);
	query(lc, ql, mid);
	query(rc, mid + 1, qr);
}

int main() {
	while (cin >> n) {
		memset(t, 0, sizeof t);
		memset(col, 0, sizeof col);
		build(1, 1, 8000);
		for (int i = 1; i <= n; i++) {
			int le, ri, c;
			cin >> le >> ri >> c;
			update(1, le + 1, ri, c);
		}
		last = -1;
		query(1, 1, 8000);
		for (int i = 0; i <= 8000; i++) {
			if (col[i] != 0) cout << i << " " << col[i] << endl;
		}
		puts("");
	}
}