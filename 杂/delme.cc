#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)

const int N= 5e5 + 10;
int bit[N];

int lowbit(int x) {
	return x & -x;
}

int add(int x, int val) {
	for (int i = x; i <= N; i += lowbit(i)) bit[i] += val;
}

int ask(int x) {
	int ret = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) ret += bit[i];
	return ret;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		int t; scanf("%d", &t);
		add(i, t);
	}
	while(m--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			add(x, y);
		} else {
			printf("%d\n", ask(y) - ask(x - 1));
		}
	}
}