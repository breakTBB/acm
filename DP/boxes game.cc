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

int dp[1010][1010], vis[1010][1010];
int a[1010];
int pre[1010];

int dfs(int l, int r) {
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    int sum = pre[r] - pre[l - 1];
    return dp[l][r] = max(sum - dfs(l + 1, r), sum - dfs(l, r - 1));
}

int main() {
    int T = read();
    while(T--) {
        memset(vis, 0, sizeof vis);
        int n = read();
        rep(i, 1, n) a[i] = read(), dp[i][i] = a[i], vis[i][i] = 1, pre[i] = pre[i - 1] + a[i];
        cout << dfs(1, n) * 2 - pre[n] << endl;
    }
}