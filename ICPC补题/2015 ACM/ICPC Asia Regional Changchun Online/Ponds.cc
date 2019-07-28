// 拓扑排序 + 并查集找连通块
// https://nanti.jisuanke.com/t/A1834

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

const int N = 1e4 + 10, M = 1e5 + 10;
int t, p, m;
ll val[N];
vector<ll> G[N];
ll in[N], vis[N], fa[N], cnt[N], sum[N];


void init() {
	rep(i, 1, p) fa[i] = i;
	rep(i, 1, N) G[i].clear();
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
	if (fa[x] == fa[y]) return;
	fa[find(x)] = find(y);
}

int main() {
	t = read();
	while (t--) {
		p = read(), m = read();
		init();
		rep(i, 1, p) val[i] = read();
		rep(i, 1, m) {
			int u = read(), v = read();
			G[u].push_back(v); G[v].push_back(u);
			in[u]++, in[v]++;
			join(u, v);
		}
		queue<int> q;
		rep(i, 1, p) {
			if (in[i] < 2) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			vis[u] = 1;
			for (int i = 0; i < G[u].size(); i++) {
				in[G[u][i]]--;
				if (!vis[G[u][i]] && in[G[u][i]] < 2) {
					q.push(G[u][i]);
				}
			}
		}
		ll ans = 0;
		rep(i, 1, p) {
			if (in[i] < 2) continue;
			int f = find(i);
			cnt[f]++;
			sum[f] += val[i];
		}

		rep(i, 1, p) {
			if (cnt[i] % 2) {
				ans += sum[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}