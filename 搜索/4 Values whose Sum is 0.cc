#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>

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
const int N = 1e5 + 10;
int a[N], b[N], n, k;

int chk(int m) {
    ll sum = 0;
    rep(i, 1, n) {
        if (a[i] > m) sum += 1ll * ceil(1.0 * (a[i] - m) /(double) (k - 1));
        if (sum > m) return 0;
    }
    return 1;
}

int main() {
    while(cin >> n) {
        ll l = 1, r = 0;
        rep(i, 1, n) scanf("%d", &a[i]), r = max(r, 1ll * a[i] + 1);
        scanf("%d", &k);
        while(l < r) {
            int m = l + (r - l) / 2;
            if (chk(m)) r = m;
            else l = m + 1;
        }
        printf("%lld\n", l);
    }
}