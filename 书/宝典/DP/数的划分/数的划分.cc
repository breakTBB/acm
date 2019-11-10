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
int dp[210][10];

int main() {
    int n = read(), k = read();
    dp[1][1] = 1;
    rep(i, 2, n) rep(j, 1, k) if (i >= j) dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
    printf("%d\n", dp[n][k]);
}