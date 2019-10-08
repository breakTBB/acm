// set 是有序的，且可以删掉被包含的！！！

#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
typedef long long ll;

using namespace std;

ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}
const int N = 3e4 + 10;
struct node {
	int a, b, c;
	bool operator < (const node& rhs) const {
		if (b == rhs.b) return a < rhs.a;
		return b < rhs.b;
	}
}nd;
int vis[N];

int main() {
	int n = read(), m = read();
	set<node> st;
	rep(i, 1, m) {
		nd.a = read(), nd.b = read(), nd.c = read();
		st.insert(nd);
	}
	int ans = 0;
	for (auto k : st) {
		int t1 = 0, t2 = 0;
		rep(i, k.a, k.b) if (vis[i]) t1++;
		t2 = k.c - t1;
		per(i, k.b, 0) {
			if (t2 <= 0) break;
			if (!vis[i]) {
				vis[i] = 1;
				ans++;
				t2--;
			}
		}
	}
	cout << ans;
}  