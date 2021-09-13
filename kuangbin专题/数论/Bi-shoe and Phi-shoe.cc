// #define POJ
#define _DEBUG

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

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define hi puts("hi!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILEIO freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
inline int inc(int x, int v, int mod) { x += v; return x >= mod ? x - mod : x; }
inline int dec(int x, int v, int mod) { x -= v; return x < 0 ? x + mod : x; }

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret *= f;
}
template <typename T, typename... Args> inline void reads(T& t, Args& ... args) {
	redi(t); redi(args...);
}
ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

const int MAXN = 1e6 + 10;
int ans[MAXN];
int prime[MAXN], v[MAXN], tot, phi[MAXN];

void seive(int N) {
	for (int i = 2; i <= N; i++) {
		if (v[i] == 0) {
			prime[++tot] = i;
			phi[i] = i - 1;
			v[i] = i;
		}
		rep(j, 1, tot) {
			if (i * prime[j] > N) break;
			v[i * prime[j]] = i;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
}


int main() {
	seive(MAXN - 1);
	rep(i, 1, MAXN - 1) {
		if (ans[phi[i]] == 0) ans[phi[i]] = i;
	}
	for (int i = MAXN - 2; i >= 1; i--) {
		if (ans[i + 1] != 0) {
			if (ans[i] != 0) ans[i] = min(ans[i], ans[i + 1]);
			else ans[i] = ans[i + 1];
		}
	}
	int t; cin >> t;
	int kase = 1;
	while (t--) {
		int n; cin >> n;
		ll sum = 0;
		rep(i, 1, n) {
			int d; cin >> d;
			sum += ans[d];
		}
		printf("Case %d: %lld Xukha\n", kase++, sum);
	}
	return 0;
}