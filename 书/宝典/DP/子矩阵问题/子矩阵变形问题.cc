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

const int N = 3010;
int mp[N][N], sum[N][N];
int m, n, w, h;

int main() {
    cin >> m >> n >> w >> h;
    rep(i, 1, m) {
        int sm = 0;
        rep(j, 1, n) {
            scanf("%d", &mp[i][j]);
            sm += mp[i][j];
            sum[i][j] = sum[i - 1][j] + sm;
        }
    }
    int ans = 0;
    rep(i, w, m) rep(j, h, n) {
        ans = max(ans, sum[i][j] - sum[i - w][j] - sum[i][j - h] + sum[i - w][j - h]);
    }
    printf("%d\n", ans);
}