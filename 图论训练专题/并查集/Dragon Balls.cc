//带权并查集
//https ://vjudge.net/problem/HDU-3635#author=634579757
//移动次数不好处理

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;

int id[maxn];
int ra[maxn];
int cs[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		id[i] = i;
		ra[i] = 1;
		cs[i] = 0;
	}
}

int find(int x) {
	if (id[x] == x) return x;
	int temp = find(id[x]);
	cs[x] += cs[id[x]];
	return id[x] = temp;
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	id[x] = y;
	ra[y] += ra[x];
	ra[x] = 0;
	cs[x]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	int cas = 0;
	while (t--) {
		int n, q;
		cin >> n >> q;
		init(n);
		printf("Case %d:\n", ++cas);
		while (q--) {
			char op;
			cin >> op;
			if (op == 'Q') {
				int t;
				cin >> t;
				int fa = find(t);
                // 两次find就不行
				printf("%d %d %d\n", fa, ra[fa], cs[t]);
			}
			else {
				int a, b;
				cin >> a >> b;
				join(a, b);
			}
		}
	}
}