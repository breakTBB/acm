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

const int mod = 1111111;
int t, n, fa[mod + 5], cnt;

struct {
	int x, y;
}a[1000010];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
	fa[find(x)]= find(y);
}

void init() {
	cnt = 0;
	rep(i, 1, mod) fa[i] = i;
}

int main() {
	read(t);
	while (t--) {
		init();
		read(n);
		while (n--) {
			read(_), read(__), read(___);
			_ %= mod, __ %= mod;
			if (___ == 1) join(_, __);
			else {a[++cnt].x = _ % mod, a[cnt].y = __ % mod; }
		}
		int f = 0;
		rep(i, 1, cnt) if (find(a[i].x) == find(a[i].y)) { puts("NO"); f = 1; break; }
		if (!f) puts("YES");
	}
    return 0;
}