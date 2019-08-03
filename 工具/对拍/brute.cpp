#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define DEBUG printf("Passing [%s] in LINE %d...\n",__FUNCTION__,__LINE__)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define HI puts("HI!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define R3(a, b, c) read(a), read(b), read(c);
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
int _, __, ___;

template<typename T> inline void read(T& ret) {
	ret = 0; int f = 1; register char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = 0; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret = f ? ret : -ret;
}
inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}
template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

const int N = 3010, mod = 998244353;
int d[N][N], c[N][N], f[N][N];
char s1[N], s2[N];
int t, n, m;

ll comb[N][N];

ll dfs(int x, int y)
{
	if (y > x) return 0;
	if (comb[x][y] != -1) return comb[x][y];
	if (y == 0) return 1;
	if (x == 0) return 0;
	return comb[x][y] = (dfs(x - 1, y - 1) + dfs(x - 1, y)) % mod;
}

int main() {
	memset(comb, -1, sizeof comb);
	// dbg(dfs(5, 2));
	read(t);
	while (t--) {
		memset(d, 0, sizeof d);
		memset(f, 0, sizeof f);
		read(n), read(m);
		scanf("%s%s", s1 + 1, s2 + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				d[i][j] = f[i][j] = 0;
		for (int i = 1; i <= n; i++) {
			f[i - 1][0] = 1;
			if (s1[i] != '0' && (n - i + 1 > m)) {
				rep(ttt, m, n - i)
					ans += dfs(n - i, ttt);
				ans %= mod;
			}
			for (int j = 1; j <= min(i, m); j++) {
				f[i][j] += f[i - 1][j];
				f[i][j] %= mod;
				d[i][j] += d[i - 1][j];
				d[i][j] %= mod;
				d[i][j] += d[i - 1][j - 1];
				d[i][j] %= mod;
				if (s1[i] > s2[j])
					d[i][j] += f[i - 1][j - 1];
				else if (s1[i] == s2[j])
					f[i][j] += f[i - 1][j - 1];
				d[i][j] %= mod;
				f[i][j] %= mod;
			}
		}
		ans += d[n][m];
		ans %= mod;
		printf("%d\n", ans);
	}

	return 0;
}