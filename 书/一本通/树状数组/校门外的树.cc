#include <bits/stdc++.h>

using namespace std;

struct BitTree {
	static const int N = 5e4 + 10;
	int bit[N];
	BitTree() {
		memset(bit, 0, sizeof bit);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x) {
		for (int i = x; i <= N; i += lowbit(i)) bit[i] += 1;
	}
	int ask(int x) {
		int ret = 0;
		for (int i = x; i >= 1; i -= lowbit(i)) ret += bit[i];
		return ret;
	}

};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	BitTree left, right;
	int op, l, r;
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) left.add(l), right.add(r);
		else printf("%d\n", left.ask(r) - right.ask(l - 1));
	}
}