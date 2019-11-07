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

const int N = 5010;
int bit[N], a[N];

inline int lowbit(int x) {
    return x & -x;
}
inline void add(int x) {
    for (int i = x; i <= N; i += lowbit(i)) bit[i] += 1;
}
inline int ask(int x) {
    int ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) ret += bit[i];
    return ret;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(bit, 0, sizeof bit);
        ll ans = 0;
        rep(i, 1, n) a[i] = read() + 1;
        rep(i, 1, n) {
            ans += a[i] - ask(a[i]) - 1;
            add(a[i]);
        }
        ll tmp = ans;
        rep(i, 1, n - 1) {
            tmp = tmp + (n - a[i]) - (a[i] - 1);
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
}