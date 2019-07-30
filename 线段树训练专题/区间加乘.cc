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

template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
}
template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}
const int N = 1e5 + 10;
struct node {
	int l, r;
	ll sum, add, mul;
}t[N << 2];
int n, m, p, op, x, y, k;

ll multiple(ll x, ll y) {
	return (x * (y % p)) % p;
}
ll addition(ll x, ll y) {
	return (x + (y % p)) % p;
}
void pushnow(int id, ll val, int option) {
	if (option == 1) {
		t[id].sum = multiple(t[id].sum, val);
		t[id].mul = multiple(t[id].mul, val);
		t[id].add = multiple(t[id].add, val);
	}
	else {
		t[id].sum = addition(t[id].sum, (1ll * t[id].r - t[id].l + 1) * val);
		t[id].add = addition(t[id].add, val);
	}
}
void pushup(int id) {
	t[id].sum = addition(t[lc].sum, t[rc].sum);
}
void pushdown(int id) {
	if (t[id].mul != 1) {
		t[lc].sum = multiple(t[lc].sum, t[id].mul);
		t[lc].mul = multiple(t[lc].mul, t[id].mul);
		t[rc].sum = multiple(t[rc].sum, t[id].mul);
		t[rc].mul = multiple(t[rc].mul, t[id].mul);
	}
	if (t[id].add != 0) {
		t[lc].sum = addition(t[lc].sum, (1ll * t[lc].r - t[lc].l + 1) * t[id].add);
		t[rc].sum = addition(t[rc].sum, (1ll * t[rc].r - t[rc].l + 1) * t[id].add);
	}

	t[lc].add = (multiple(t[lc].add, t[id].mul) + t[id].add) % p;
	t[rc].add = (multiple(t[rc].add, t[id].mul) + t[id].add) % p;

	t[id].add = t[id].add = 0;
	t[id].mul = t[id].mul = 1;
}
void build(int id, int l, int r) {
	t[id].l = l, t[id].r = r, t[id].mul = 1;
	if (l == r) {
		read(t[id].sum);
		t[id].sum %= p;
		return;
	}
	build(lc, l, mid), build(rc, mid + 1, r), pushup(id);
}
void update(int id, int ql, int qr, int val) {
	if (t[id].l > qr || t[id].r < ql) return;
	if (ql <= t[id].l && t[id].r <= qr) { pushnow(id, val, op); return; }
	pushdown(id);
	if (qr <= mid) update(lc, ql, qr, val);
	else if (ql > mid) update(rc, ql, qr, val);
	else update(lc, ql, mid, val), update(rc, mid + 1, qr, val);
	pushup(id);
}
ll query(int id, int ql, int qr) {
	if (t[id].l > qr || t[id].r < ql) return 0;
	if (ql <= t[id].l && t[id].r <= qr) return t[id].sum;
	pushdown(id);
	if (qr <= mid) return query(lc, ql, qr);
	else if (ql > mid) return query(rc, ql, qr);
	else return (query(lc, ql, mid) + query(rc, mid + 1, qr)) % p;
}
int main() {
	FIN;
	read(n), read(m), read(p);
	build(1, 1, n);
	while (m--) {
		read(op); read(x); read(y);
		if (op == 1) {
			read(k);
			update(1, x, y, k);
		}
		else if (op == 2) {
			read(k);
			update(1, x, y, k);
		}
		else {
			printf("%lld\n", query(1, x, y));
		}
	}
}