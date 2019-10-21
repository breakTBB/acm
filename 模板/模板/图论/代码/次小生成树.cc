#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <stack>
#include <vector>
#include <climits>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define dbg(x) cout << #x << ": " << x << endl;
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000 + 10, maxe = 1000 * 1000 / 2 + 5, INF = 0x3f3f3f3f;
int n, m, fa[maxn], dis[maxn][maxn];
struct Edge {
	int u, v, w;
	bool vis;
}edge[maxe];
vector<int> G[maxn];

bool cmp(const Edge& a, const Edge& b) {
	return a.w < b.w;
}

void Init() {
	for (int i = 1; i <= n; i++) {
		G[i].clear();
		G[i].push_back(i);
		fa[i] = i;
	}
}

int Find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

int Kruskal() {
	sort(edge + 1, edge + 1 + m, cmp);
	Init();
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (cnt == n - 1) break;
		int fx = Find(edge[i].u), fy = Find(edge[i].v);
		if (fx != fy) {
			cnt++;
			edge[i].vis = true;
			ans += edge[i].w;
			int len_fx = G[fx].size(), len_fy = G[fy].size();
			for (int j = 0; j < len_fx; j++)
				for (int k = 0; k < len_fy; k++)
					dis[G[fx][j]][G[fy][k]] = dis[G[fy][k]][G[fx][j]] = edge[i].w;
			fa[fx] = fy;
			for (int j = 0; j < len_fx; j++)
				G[fy].push_back(G[fx][j]);
		}
	}
	return ans;
}

int Second_Kruskal(int MST) {
	int ans = INF;
	for (int i = 1; i <= m; i++)
		if (!edge[i].vis)
			ans = min(ans, MST + edge[i].w - dis[edge[i].u][edge[i].v]);
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
			edge[i].vis = false;
		}
		int MST = Kruskal();
		int Second_MST = Second_Kruskal(MST);
		printf("%d\n", Second_MST);
	}
	return 0;
}