#include <bits/stdc++.h>
#define rep(i, a, b) for (register int i = a; i <= b; i++)
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

const int N = 2e4 + 10, M = 1e5 + 10;
int fa[N], ans[N], num[N];
int n, m, q, tmp;

void init() {
	rep(i, 1, n) fa[i] = i, num[i] = 1;
}

int calc(int x) { return x * (x - 1); }

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
	if (fa[x] == fa[y]) return;
	x = find(x);
	y = find(y);
	if (y < x) swap(x, y);
	fa[y] = x;
	num[x] += num[y];
}

struct Node {
	int u, v, w;
	bool operator < (const Node a) const {
		return w < a.w;
	}
}E[M];

struct Qry {
	int q, id;
	bool operator < (const Qry a) const {
		return q < a.q;
	}
}Q[5010];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = read();
	while (t--) {
		tmp = 0;
		n = read(), m = read(), q = read();
		init();
		rep(i, 1, m) E[i].u = read(), E[i].v = read(), E[i].w = read();
		sort(E + 1, E + m + 1);
		rep(i, 1, q) {
			Q[i].q = read();
			Q[i].id = i;
		}
		sort(Q + 1, Q + q + 1);
        int i = 1, j = 1;
		for (; i <= q; i++) {
			for (; j <= m; j++) {
				if (Q[i].q >= E[j].w) {
					int u = find(E[j].u);
					int v = find(E[j].v);
					if (u == v) continue;
					tmp += calc(num[u] + num[v]) - calc(num[u]) - calc(num[v]);
					join(E[j].u, E[j].v);
				}
				else break;
			}
			ans[Q[i].id] = tmp;
		}
		rep(i, 1, q) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}