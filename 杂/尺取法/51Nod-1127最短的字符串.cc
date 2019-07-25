// 我是个不读题的傻逼
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
using namespace std;

inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

char mp[1010][1010];
int up[1010][1010], l[1010][1010], r[1010][1010];

void init() {
	memset(up, 0, sizeof up);
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
}

int cnt[200];

int main() {
	string s; cin >> s;
	int m = 0;
	int l = 0, r = 0, ans = 0x3f3f3f3f;
	int len = s.length();
	for (;;) {
		while (r < len && m != 26) if (cnt[s[r++]]++ == 0) m++;
		if (m != 26) break;
		if (m == 26) ans = min(ans, r - l);
		if (--cnt[s[l++]] == 0) m--;
	}
	if (ans == 0x3f3f3f3f) cout << 0;
	else cout << ans;
}