// 区间模拟贪心
// 抽象出每一次选择的动作
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

int n;
double L, W;
int p, r;

struct node {
	double x, y, r;
	bool operator < (const node& rhs) {
		if (x != rhs.x) return x < rhs.x;
		return y > rhs.y;
	}
}line[15010];

node get(int p, int r) {
	if (r < W) {
		node ret;
		ret.x = L + 1;
		ret.y = L + 1;
		return ret;
	}
	double len = sqrt(r * r - W * W);
	node ret;
	ret.x = p - len, ret.y = p + len, ret.r = r;
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lf%lf", &n, &L, &W);
		W /= 2;
		rep(i, 1, n) {
			scanf("%d%d", &p, &r);
			line[i] = get(p, r);
		}
		sort(line + 1, line + n + 1);
		int ans = 0, cur = 0;
		double last = 0;
		while (line[cur].y < L && cur <= n) {
			int mx = cur, j = cur;
			for (int j = cur + 1; line[j].x <= last && j <= n; j++) {
				if (line[j].y > line[mx].y) {
					mx = j;
				}
			}
			if (mx == cur) break;
			ans++;
			last = line[mx].y;
			cur = mx;
		}
			
		if (last < L) puts("-1");
		else printf("%d\n", ans);
	}
}