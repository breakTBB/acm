#include <bits/stdc++.h>
#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define HI puts("hi!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define SKINIT(sk) while(sk.size()) sk.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
}

inline ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

char str[110];
int dp[110][110];

int main() {
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	rep(i, 1, n) dp[i][i] = 1;
	rep(len, 2, n) {
		rep(l, 1, n - len + 1) {
			int r = l + len - 1;
			dp[l][r] = 0x3f3f3f3f;
			if ((str[l] == '(' && str[r] == ')') || (str[l] == '[' && str[r] == ']')) {
				dp[l][r] = dp[l + 1][r - 1];
			}
			rep(k, l, r - 1) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			/*if ((str[l] == '(' && str[r] == ')') || (str[l] == '[' && str[r] == ']')) {
				dp[l][r] = dp[l + 1][r - 1];
			}
			这个逻辑有问题，可用 [][] hack掉
			else {
				rep(k, l, r -1) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}*/
		}
	}
	cout << dp[1][n];
}