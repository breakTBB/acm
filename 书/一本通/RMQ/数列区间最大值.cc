#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int a[N],st[N][20], lg[N];

int query(int l, int r) {
	int t = lg[r - l + 1];
	return max(st[l][t], st[r - (1 << t) + 1][t]);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &st[i][0]);
	rep(i, 2, n) lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	while (q--) {
		int le, ri;
		scanf("%d%d", &le, &ri);
		printf("%d\n", query(le, ri));
	}
}