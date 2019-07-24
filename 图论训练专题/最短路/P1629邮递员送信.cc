// spfa + 反向建图
// spfa 取出点后忘记vis[x] = 0;
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 100010;
typedef pair<pair<int, int>, int> p;
vector<p> node(M);
int ver[M << 1], edge[M << 1], head[N], nxt[M<<1], tot;
int vis[N], d[N];
queue<int> q;
int n, m;

void ins(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z;
	nxt[tot] = head[x]; head[x] = tot;
}

void spfa() {
	memset(d, 0x3f, sizeof d);
	memset(vis, 0, sizeof vis);
	d[1] = 0;
	q.push(1);
	vis[1] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		vis[x] = 0;
		for (int i = head[x]; i; i = nxt[i]) {
			if (d[ver[i]] > d[x] + edge[i]) {
				d[ver[i]] = d[x] + edge[i];
				if (!vis[ver[i]]) vis[ver[i]] = 1, q.push(ver[i]);
			}
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		node[i] = { {u, v}, w };
	}
	for (int i = 1; i <= m; i++) {
		ins(node[i].first.first, node[i].first.second, node[i].second);
	}
	spfa();
	int ans = 0;
	for (int i = 2; i <= n; i++) ans += d[i];
	tot = 0;
	memset(ver, 0, sizeof ver);
	memset(edge, 0, sizeof edge);
	memset(nxt, 0, sizeof nxt);
	memset(head, 0, sizeof head);
	for (int i = 1; i <= m; i++) {
		ins(node[i].first.second, node[i].first.first, node[i].second);
	}
	spfa();
	for (int i = 2; i <= n; i++) {
		ans += d[i];
	}
	cout << ans;
}