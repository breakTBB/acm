#include <bits/stdc++.h>

#define dbg(x) cout << #x << ": " << x << endl;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define PI acos(-1.0)
typedef long long ll;

using namespace std;

struct node {
	int pos, dep;
	node() {}
	node(int pos, int dep) : pos(pos), dep(dep) {}
};
int n, a, b;
int delta[2100];
node q[1000010];
int vis[2100];
int head, tail;

int main() {
	cin >> n >> a >> b;
	rep(i, 1, n) cin >> delta[i];
	q[tail++] = node{ a, 0 };
	while (head < tail) {
		node now = q[head++];
        vis[now.pos] = 1;
		if (now.pos == b) {
			cout << now.dep << endl;
			return 0;
		}
		int up = now.pos + delta[now.pos];
		if (up <= n && !vis[up]) q[tail++] = node{ up, now.dep + 1 };
		int down = now.pos - delta[now.pos];
		if (down >= 1 && !vis[down]) q[tail++] = node{ down, now.dep + 1 };
	}
	puts("-1");
}