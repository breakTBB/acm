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

double dp[20][200010];
int val[20];
double posibility[20][20];

int main() {
    int n = read(), C = read();
    rep(i, 1, n) {
        cin >> val[i];
        rep(j, 0, C / val[i]) cin >> posibility[i][j];
    }
    rep(i, 0, n) rep(j, 0, C) dp[i][j] = 1;
    rep(i, 1, n) {
        rep(j, 0, C) {
            double mx = 0;
            rep(k, 0, j) {
                mx = max(mx, dp[i - 1][k] * posibility[i][(j - k) / val[i]]);
            }
            dp[i][j] = mx;
        }
    }
    cout << fixed << setprecision(4) << dp[n][C] << endl;
}