// 二维并查集
// https://vjudge.net/problem/HDU-5652

#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define pii pair<int, int>
typedef long long ll;

using namespace std;

int read() {
	register int ret = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar(); }
	return ret;
}

struct node {
	int x, y;
	node() {}
	node(int x, int y) : x(x), y(y) {}
	bool operator == (const node& rhs) {
		return x == rhs.x && y == rhs.y;
	}
	bool operator != (const node& rhs) {
		return x != rhs.x || y != rhs.y;
	}
};
node fa[510][510];
int mp[510][510];
node find(node k) {
	return k == fa[k.x][k.y] ? k : fa[k.x][k.y] = find(fa[k.x][k.y]);
}
void join(node x, node y) {
	node tx = find(x), ty = find(y);
	if (tx != ty) {
		fa[tx.x][tx.y] = ty;
	}
}
int main() {
	int T = read();
	while (T--) {
		rep(i, 1, 510) rep(j, 1, 510) fa[i][j].x = i, fa[i][j].y = j;
		int n = read(), m = read();
		rep(i, 1, n) rep(j, 1, m) {
			scanf("%1d", &mp[i][j]);
		}
		rep(i, 1, n) rep(j, 1, m) {
			if (mp[i][j]) {
				rep(dx, -1, 1) rep(dy, -1, 1) {
					if (mp[i + dx][j + dy]) join({ i, j }, { i + dx, j + dy });
				}
			}
		}
		rep(i, 1, n) join({ 0, 0 }, { i, 1 }), join({ 510, 510 }, { i, m });
		int q = read();
		int f = 0, time = q;
		while (q--) {
			int x = read(), y = read();
			x++, y++;
			mp[x][y] = 1;
			if (f) continue;
			rep(dx, -1, 1) rep(dy, -1, 1) {
				if (mp[x + dx][y + dy]) join({ x, y }, { x + dx, y + dy });
			}
			if (find({ 0, 0 }) == find({ 510, 510 })) {
				f = 1;
				cout << time - q << endl;
			}
		}
		if (!f) puts("-1");
	}
}