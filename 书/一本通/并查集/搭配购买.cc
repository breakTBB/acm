// 01 package + disjoint set
// https://loj.ac/problem/312314524
#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)

const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int N = 1e4 + 10;
int fa[N], W[N], V[N], WW[N], VV[N], dp[N];
int n, m, w, u, v;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) fa[x] = y, W[y] += W[x], V[y] += V[x];
}

int main() {
	scanf("%d%d%d", &n, &m, &w);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, n) {
		scanf("%d%d", &W[i], &V[i]);
	}
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		join(u, v);
	}
	int cnt = 0;
	rep(i, 1, n) {
		if (find(i) == i) {
			WW[++cnt] = W[i];
			VV[cnt] = V[i];
		}
	}
	rep(i, 1, cnt) {
		for (int j = w; j >= WW[i]; j--)
			dp[j] = max(dp[j], dp[j - WW[i]] + VV[i]);
	}
	printf("%d\n", dp[w]);
}