#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}
int dp[110][110];

int main() {
    int n = read();
    int mn = inf;
    rep(len, 2, n) {
        rep(l, 1, n - len + 1) {
            int r = l + len - 1;
            rep(k, l + 1, r - 1) {
                dp[l][r] = min(dp[l][r], k + dp[l][k - 1] + dp[k + 1][r]);
            }
            dp[l][r] = max(dp[l][r], l + dp[l + 1][r]);
            dp[l][r] = max(dp[l][r], r + dp[l][r - 1]);
            mn = min(mn, dp[l][r]);
        }
    }
    cout << mn << endl;
}