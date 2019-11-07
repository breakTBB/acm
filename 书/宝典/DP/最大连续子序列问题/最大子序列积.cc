#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

const int N = 1e6 + 10;
ll mx[N], mn[N], now, mxx, mnn;

int main() {
	mxx = LLONG_MIN, mnn = LLONG_MAX;
	int n = read();
	scanf("%lld", &now);
	mx[1] = mn[1] = now;
	rep(i, 2, n) {
		scanf("%lld", &now);
		mx[i] = max(max(mx[i - 1] * now, now), mn[i - 1] * now);
		mn[i] = min(min(mx[i - 1] * now, now), mn[i - 1] * now);
		mxx = max(mxx, mx[i]);
		mnn = min(mnn, mn[i]);
	}
	printf("%lld\n%lld", mxx, mnn);
}