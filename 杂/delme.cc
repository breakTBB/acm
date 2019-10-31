#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 6e5 + 10;
int ver[N], head[N], nxt[N], type[N], tot, id;
map<int, char> dir;
int vis[N];
int n, m, s, t, u, v;
int ans;

void ins(int u, int v, int w) {
	ver[++tot] = v;
	if (w - 1) type[tot] = ++id;
	nxt[tot] = head[u], head[u] = tot;
}

void dfs1(int st) {
	vis[st] = 1;
	for (int i = head[st]; i; i = nxt[i]) {
	if (vis[ver[i]]) continue;
		ans++;
		if (!type[i]) dfs1(ver[i]);
		else if (type[i] & 1) dir[(type[i] + 1) / 2] = '+', dfs1(ver[i]);
		else dir[(type[i] + 1) / 2] = '-', dfs1(ver[i]);
	}
}

void dfs2(int st) {
	vis[st] = 1;
	for (int i = head[st]; i; i = nxt[i]) {
		if (vis[ver[i]]) continue;
		if (!type[i]) ans++, dfs2(ver[i]);
		else if (type[i] & 1) dir[(type[i] + 1) / 2] = '-';
		else dir[(type[i] + 1) / 2] = '+';
	}
}

int main() {
	cin >> n >> m >> s;
	rep(i, 1, m) {
		cin >> t >> u >> v;
		ins(u, v, t);
		if (t - 1) ins(v, u, t);
	}
	rep(i, 1, id) dir[i] = '+';
	dfs1(s);
	cout << ans + 1 << endl;
	for (int i = 1; i <= id / 2; i++) cout << dir[i];
	puts("");
	ans = 0;
	memset(vis, 0, sizeof vis);
	dfs2(s);
	cout << ans + 1 << endl;
	for (int i = 1; i <= id / 2; i++) cout << dir[i];
	puts("");
}