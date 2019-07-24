// 拓扑排序
// https://vjudge.net/problem/HDU-1285

#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
priority_queue<int, vector<int>, greater<int>> q;
bool mp[maxn][maxn];
int in[maxn];

void topo(int n) {
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);
	}
	int cnt = 1;
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		cout << v;
		if (cnt != n) putchar(' ');
		else putchar('\n');
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (!mp[v][i]) continue;
			in[i]--;
			if (!in[i]) q.push(i);
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		while (m--) {
			int u, v;
			cin >> u >> v;
			mp[u][v] = 1;
			in[v]++;
		}
		topo(n);
	}
}