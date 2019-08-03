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

const int N = 510;
const int K = 110;
int n, k;
int l[N], dp[N][K][K];
char tmp[N];

int main() {
	memset(dp, ~63, sizeof dp);
	read(n), read(k);
	scanf("%s", tmp + 1);
	for (int i = 1; i <= n; i++) {
		if (tmp[i] == 'z') l[i] = 1;
		else l[i] = 0;
	}
	dp[0][0][0] = dp[1][0][0] = dp[1][l[1]][l[1]] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= k; ++j)
			for (int jj = 0; jj <= k; ++jj) {
				dp[i][j][jj] = dp[i - 1][j][jj];
				//jz
				if (!l[i - 1] && l[i]) 
					dp[i][j][jj] = max(dp[i][j][jj], dp[i - 2][j][jj] + 1);
				//zz
				if (jj && l[i] && l[i - 1]) 
					dp[i][j][jj] = max(dp[i][j][jj], dp[i - 2][j][jj - 1] + 1);
				//jj
				if (j && !l[i] && !l[i - 1]) 
					dp[i][j][jj] = max(dp[i][j][jj], dp[i - 2][j - 1][jj] + 1);
				//zj
				if (j && jj && !l[i] && l[i - 1]) 
					dp[i][j][jj] = max(dp[i][j][jj], dp[i - 2][j - 1][jj - 1] + 1);
			}
	int ans = 0;
	rep(i, 0, k) {
		ans = max(ans, dp[n][i][i]);
	}
	printf("%d\n", ans);
	return 0;
}