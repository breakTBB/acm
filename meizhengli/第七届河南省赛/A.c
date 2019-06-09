#include <stdio.h>
#include <string.h>

int n, m;
#define inf 0x3f3f3f3f
#define N 1010
int dis[N];
int cost[N][N];
int vis[N];


void dij(int beg) {
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[beg] = 1;
	for (int i = 1; i <= n; ++i)
		dis[i] = cost[i][beg];
	for (int i = 1; i <= n; i++) {
		int k = -1;
		int mn = inf;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j] && dis[j] < mn) {
				mn = dis[j];
				k = j;
			}
		}
		if (k == -1) break;
		vis[k] = 1;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && max(dis[k], cost[i][k]) < dis[i])
				dis[i] = max(dis[k], cost[i][k]);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(cost, inf, sizeof cost);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		cost[a][b] = cost[b][a] = min(cost[b][a], c);
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		dij(a);
		if (dis[b] == inf) printf("-1\n");
		else printf("%d\n", dis[b]);
	}
}