// 从无序到有序 降维！！！
// 也就是离线处理的基本动机

#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid ((l + r) >>  1)
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int N = 32e3 + 10;
int cnt[N], bit[N][N];
int lowbit(int x) {
	return x & -x;
}
void update(int x, int y, int val) {
	for (int i = x; i <= N; i += lowbit(i))
		for (int j = y; j <= N; j += lowbit(j))
			bit[i][j] += val;
}
int query(int x, int y) {
	int ret = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		for (int j = y; j >= 1; j -= lowbit(j))
			ret += bit[i][j];
	return ret;
}

int x, y;

int main() {
	int n;
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &x, &y);
		cnt[query(x, y)]++;
		update(x, y, 1);
	}
	rep(i, 0, n - 1) printf("%d\n", cnt[i]);
}