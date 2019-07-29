// 拓扑排序
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

const int N = 1010;
struct node {
	int l, r, val, mx;
}t[N << 2];

void pushup(int id) {
	t[id].mx = max(t[lc].mx, t[rc].mx);
}

void build(int id, int l, int r) {
	t[id].l = l; t[id].r = r;
	if (l == r) {
		t[id].mx = read();
		return;
	}
	build(lc, l, mid), build(rc, mid + 1, r), pushup(id);
}

int query(int id, int ql, int qr) {
	if (t[id].l > qr || t[id].r < ql) return INT_MIN;
	if (ql <= t[id].l && t[id].r <= qr) return t[id].mx;
	if (qr <= mid) return query(lc, ql, qr);
	else if (ql > mid) return query(rc, ql, qr);
	else return max(query(lc, ql, mid), query(rc, mid + 1, qr));
}

int T, n, q, le, ri;

int main() {
	T = read();
	while (T--) {
		n = read();
		build(1, 1, n);
		q = read();
		while (q--) {
			le = read(), ri = read();
			printf("%d\n", query(1, le, ri));
		}
	}
}