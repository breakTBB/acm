// char string的问题  卡内存 复用的思想
// https://nanti.jisuanke.com/t/A1833
#include <bits/stdc++.h>
using namespace std;

struct psn {
	int val, order;
	bool operator < (psn p) const {
		if (val != p.val) return val < p.val;
		return order > p.order;
	}
};

inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

int t, n, m, q;
priority_queue<psn> qu;
psn v[150001];
psn ans[150001];
char name[150001][201];
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	t = read();
	while (t--) {
		n = read(); m = read(); q = read();
		mp.clear();
		for (register int i = 1; i <= n; i++) {
			scanf("%s%d", name[i], &v[i].val);
			v[i].order = i;
		}
		for (register int _ = 1; _ <= m; _++) {
			int x, y;
			x = read(); y = read();
			mp[x] = y;
		}
		int cnt = 0;
		for (register int i = 1; i <= n; i++) {
			qu.push(v[i]);
			if (mp[i] != 0) {
				while (qu.size() && mp[i]--) {
					ans[++cnt] = qu.top();
					qu.pop();
				}
			}
		}
		while (qu.size()) ans[++cnt] = qu.top(), qu.pop();
		while (q--) {
			int tmp = read();
			printf("%s", name[ans[tmp].order]);
			if (q) putchar(' ');
		}
		puts("");
	}
}