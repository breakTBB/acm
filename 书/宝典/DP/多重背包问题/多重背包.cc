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

int W[20], V[20], C[20];
int dp[300];

int main() {
    int m = read(), n = read();
    rep(i, 1, n) W[i] = read(), V[i] = read(), C[i] = read();
    rep(i, 1, n) rep(j, 1, C[i]) per(k, m, W[i]) dp[k] = max(dp[k], dp[k - W[i]] + V[i]);
    printf("%d\n", dp[m]);
}