#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

int v[N][N][N], n, m, s, le, ri;

struct status {
	int a, b, c, d;
	status() {}
	status(int e, int f, int g, int h) : a(e), b(f), c(g), d(h) {}
} q[N * N * N];

void pour(int a, int b, int c, int d) {
	if (!v[a][b][c]) {
		v[a][b][c] = 1;
		q[ri++] = status(a, b, c, d + 1);
	}
}

int bfs() {
	int a, b, c, d;
	le = ri = 0;
	q[ri++] = status(s, 0, 0, 0);
	v[s][0][0] = 1;
	while (le < ri) {
		a = q[le].a, b = q[le].b, c = q[le].c, d = q[le].d; le++;
		if (a == s / 2 || b == s / 2 || c == s / 2) {
			if (a == 0 || b == 0 || c == 0)
				return d;
		}
		pour(a - n + b, n, c, d); // s -> n
		pour(a - m + c, b, m, d); // s -> m
		pour(a + b, 0, c, d); // n -> s
		pour(a + c, b, 0, d); // m -> s
		if (b > m - c) pour(a, b - m + c, m, d);
		else pour(a, 0, b + c, d);
		if (c > n - b) pour(a, n, c - n + b, d); // m -> n
		else pour(a, b + c, 0, d);
	}
	return 0;
}

int main() {
	int ans;
	while (scanf("%d%d%d", &s, &n, &m), n) {
		memset(v, 0, sizeof v);
		ans = 0;
		if (s % 2 == 0) ans = bfs();
		
		if (!ans) puts("NO");
		else printf("%d\n", ans);
	}
	return 0;
}