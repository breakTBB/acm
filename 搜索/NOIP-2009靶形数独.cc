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

const int N = 15;
int mp[N][N], a[N][N], sum, ans = -1, tot;
bool vis[N][N], row[N][N], col[N][N], board[N][N];
int w[N][N] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6},
};

inline int check(int x, int y) {
	if (x <= 3) {
		if (y <= 3) return 1;
		if (y <= 6) return 2;
		return 3;
	}
	else if (x <= 6) {
		if (y <= 3) return 4;
		if (y <= 6) return 5;
		return 6;
	}
	else {
		if (y <= 3) return 7;
		if (y <= 6) return 8;
		return 9;
	}
}

inline void dfs(int used, int sum) {
	if (used == 0) { ans = max(ans, sum); return; }
	int mx = INT_MAX, xx, yy, op;
	rep(i, 1, 9) rep(j, 1, 9) {
		if (!vis[i][j]) {
			int cnt  = 0;
			rep(p, 1, 9) {
				if (!col[j][p] && !row[i][p] && !board[check(i, j)][p]) cnt++;
			}
			if (cnt < mx) mx = cnt, xx = i, yy = j;
		}
	}
	rep(i, 1, 9) {
		if (!row[xx][i] && !col[yy][i] && !board[check(xx, yy)][i]) {
			row[xx][i] = col[yy][i] = board[check(xx, yy)][i] = vis[xx][yy] = 1;
			dfs(used - 1, sum + w[xx][yy] * i);
			row[xx][i] = col[yy][i] = board[check(xx, yy)][i] = vis[xx][yy] = 0;
		}
	}
}

int main() {
	rep(i, 1, 9)
		rep(j, 1, 9) {
			read(a[i][j]);
			if (a[i][j]) {
				tot++;
				sum += a[i][j] * w[i][j];
				row[i][a[i][j]] = col[j][a[i][j]] = vis[i][j] = board[check(i, j)][a[i][j]] = 1;
			}
		}
	dfs(81 - tot, sum);
	cout << ans;
	return 0;
	
}