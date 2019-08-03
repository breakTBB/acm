// https://www.luogu.org/problem/P1466
// 01背包

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
	ret = 0; int f = 1; char c = getchar();
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

const int N = 100010;
int n, s;
ll dp[N];

int main() {
	read(n);
	s = n * (n + 1) / 2;
	if (s & 1) {
		puts("0");
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = s / 2; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	printf("%d", dp[s / 2] / 2);
	return 0;
}