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

const int N = 2010;
int k;
char s1[N], s2[N];
int dp[N][N];

int calc(int i, int j) {
	return abs((s1[i] - 'a') - (s2[j] - 'a'));
}

int main() {
	scanf("%s%s%d", s1 + 1, s2 + 1, &k);
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i <= len1; ++i)
		for (int j = 0; j <= len2; ++j) {
			if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + k);
			if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + k);
			if (i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + calc(i, j));
		}
	printf("%d\n", dp[len1][len2]);
}