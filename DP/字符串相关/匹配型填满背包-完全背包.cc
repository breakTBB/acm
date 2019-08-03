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

const int M = 1e6 + 10;
int n;
string c[] = { "", "one", "puton", "out", "output", "in", "input" };
int len[] = { 0, 3, 5, 3, 6, 2, 5 };
int dp[M];

int main() {
	scanf("%d", &n);
	while (n--) {
		string s;
		int l;
		memset(dp, 0, sizeof dp);
		cin >> s;
		l = s.length();
		dp[0] = 1;
		for (int j = 1; j <= l; j++)
			if (s[j - 1] == 'e' || s[j - 1] == 'n' || s[j - 1] == 't')
				for (int i = 1; i <= 6; ++i)
					if (j - len[i] >= 0)
						if (s[j - len[i]] == 'o' || s[j - len[i]] == 'p' || s[j - len[i]] == 'i')
							if (s.substr(j - len[i], len[i]) == c[i])
								dp[j] = dp[j] | dp[j - len[i]];
		if (dp[l]) puts("YES");
		else puts("NO");
	}
}