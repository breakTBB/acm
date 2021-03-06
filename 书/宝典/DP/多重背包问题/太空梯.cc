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

int W[410], L[410], C[410], dp[4000010];
int main() {
    int n = read();
    int sum = 0;
    rep(i, 1, n) {
        int a = read(), b = read(), c = read();
        W[i] = a, L[i] = b, C[i] = c;
        sum = max(sum, L[i]);
    }
    rep(i, 1, n) rep(j, 1, C[i]) per(k, sum, W[i]) if (k <= L[i]) dp[k] = max(dp[k], dp[k - W[i]] + W[i]);
    printf("%d\n", dp[sum]);
}