#include <bits/stdc++.h>
#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi!");
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

const int N = 400;
int sum[N], a[N], mx[N][N], mn[N][N];

int main() {
	int n;
	cin >> n;
	rep(i, 1, n) a[i] = a[i + n] = read();
	rep(i, 1, 2 * n) sum[i] = sum[i - 1] + a[i];
	rep(len, 2, n) {
		rep(l, 1, 2 * n - len) {
			int r = l + len - 1;
			mx[l][r] = -inf;
			mn[l][r] = inf;
			rep(k, l, r - 1) {
				mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r] + sum[r] - sum[l - 1]);
				mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r] + sum[r] - sum[l - 1]);
			}
		}
	}
	int mmin = inf, mmax = -inf;
	rep(i, 1, n) {
		mmin = min(mmin, mn[i][i + n - 1]);
		mmax = max(mmax, mx[i][i + n - 1]);
	}
	cout << mmin << '\n' << mmax;
}