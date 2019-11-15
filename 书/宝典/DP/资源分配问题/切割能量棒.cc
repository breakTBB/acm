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

int dp[60][60], p[60];

int main() {
    int L;
    while(L = read(), L) {
        int n = read();
        rep(i, 1, n) p[i] = read();
        p[n + 1] = L;
        rep(len, 2, n + 1) {
            rep(l, 1, n - len + 2) {
                int r = l + len - 1;
                dp[l][r] = inf;
                rep(k, l, r - 1) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + p[r] - p[l - 1]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[1][n + 1]);
    }
}