// 枚举最后一个钓鱼的地方

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

struct node {
	int d, t;
	bool operator < (const node& rhs) const {
		return d < rhs.d;
	}
}A[110];
priority_queue<node> q;
int dis[110];

int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	h *= 60;
	rep(i, 1, n) scanf("%d", &A[i].d);
	rep(i, 1, n) scanf("%d", &A[i].t);
	rep(i, 2, n) scanf("%d", &dis[i]);
	int ans = 0, sum = 0;
	rep(i, 1, n) {
		h -= 5 * dis[i];
		int th = h;
		sum = 0;
		rep(j, 1, i) q.push(A[j]);
		while (th > 0) {
			node now = q.top(); q.pop();
			if (now.d <= 0) break;
			sum += now.d;
			now.d -= now.t;
			q.push(now);
			th -= 5;
		}
		ans = max(ans, sum);
		while (!q.empty()) q.pop();
	}
	printf("%d\n", ans);
}