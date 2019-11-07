//#define POJ
#ifdef POJ
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#else
#include <bits/stdc++.h>
#endif // POJ

#ifdef _DEBUG
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define dbg(x)
#endif // _DEBUG
#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define hi puts("hi!");
#define gkd ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
inline int inc(int x, int v, int mod) { x += v; return x >= mod ? x - mod : x; }
inline int dec(int x, int v, int mod) { x -= v; return x < 0 ? x + mod : x; }
const int inf = 0x3f3f3f3f;
//const double pi = acos(-1);
const double eps = 1e-8;
int _, __, ___;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret = ret * f;
}
#ifndef POJ
template <typename T, typename... Args> inline void read(T& t, Args& ... args) {
	read(t); read(args...);
}
#endif // !POJ

ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

const int N = 1010;
int f[20][N], a[N];
int ans = -inf;

int main() {
	int n, k;
	read(n, k);
	rep(i, 1, n) a[i] = read();
	rep(i, 1, k) {
		rep(j, 1, n) {
			f[i][j] = f[i][j - 1] + a[j];
			rep(m, i - 1, j - 1) {
				f[i][j] = max(f[i][j], f[i - 1][m] + a[j]);
			}
		}
		ans = max(f[k][n], ans);
	}
	cout << ans;
}