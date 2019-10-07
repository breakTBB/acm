// 反向处理
// https://loj.ac/problem/312314523
#include <bits/stdc++.h>

#ifdef _DEBUG
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi!");
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#endif // _DEBUG

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)

const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int N = 1010;
int fa[N], cnt[N];
int mp[N][N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) fa[x] = y, cnt[y] += cnt[x];
}

int main() {
	int n;
	scanf("%d", &n);
	rep(i, 1, n) fa[i] = i, cnt[i] = 1;
	rep(i, 1, n) {
		scanf("%d", &mp[i][0]);
		rep(j, 1, mp[i][0]) {
			scanf("%d", &mp[i][j]);
		}
	}
	per(i, n, 1) {
		rep(j, 1, mp[i][0]) {
			if (mp[i][j] < i) continue;
			int tx = find(mp[i][j]), ty = find(i);
			if (tx != ty) {
				join(tx, ty);
				if (cnt[ty] > (n / 2)) {
					cout << i << endl;
					return 0;
				}
			}
		}
	}
}