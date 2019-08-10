#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
const int inf = 0x3f3f3f3f;
int _, __, ___;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
}
ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

const int N = 160;
struct node {
	int x, y;
}a[N];
double cal(int i, int j) {
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
}
int n, tmp;
double dis[N][N], d[N];
int main() {
	n = read();
	rep(i, 1, n) a[i].x = read(), a[i].y = read();
	rep(i, 1, n) rep(j, 1, n) {
		tmp = read();
		if (tmp) dis[i][j] = cal(i, j);
		else if (i != j) dis[i][j] = inf;
	}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
		if (dis[i][j] > dis[i][k] + dis[k][j])
			dis[i][j] = dis[i][k] + dis[k][j];
	}
	double di = 0;
	rep(i, 1, n) rep(j, 1, n) {
		if (dis[i][j] != inf) d[i] = max(dis[i][j], d[i]);
		di = max(di, d[i]);
	}
	rep(i, 1, n) rep(j, 1, n) {
		if (dis[i][j] == inf)
	}
}