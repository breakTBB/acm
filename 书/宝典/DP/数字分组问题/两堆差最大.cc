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
int a[30], dp[100010];

int main() {
    int n = read();
    int mx = 0, sum = 0;
    dp[0] = 1;
    rep(i, 1, n) a[i] = read(), mx = max(mx, a[i]), sum += a[i];
    rep(i, 1, n) {
        per(j, sum / 2, a[i]) {
            dp[j] = dp[j] + dp[j - a[i]];
        }
    }
    rep(i, (sum - mx + 1) / 2, sum / 2) {
        if (dp[i]) {
            cout << sum - 2 * i << endl;
            return 0;
        }
    }
}