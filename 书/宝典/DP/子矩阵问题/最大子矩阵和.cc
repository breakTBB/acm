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

const int N = 210;
int mp[N][N], pre[N][N], dp[N], ans = 0;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", &mp[i][j]);
    rep(i, 1, n) rep(j, 1, m) pre[i][j] = pre[i - 1][j] + mp[i][j];
    rep(up, 1, n) rep(bottom, up, n) {
        int sum = 0;
        rep(i, 1, m) {
            sum += pre[bottom][i] - pre[up - 1][i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
    }
    printf("%d", ans);
}