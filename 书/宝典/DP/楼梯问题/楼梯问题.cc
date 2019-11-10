#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

ll dp[500];

int main() {
    int n; cin >> n;
    dp[0] = 1;
    rep(i, 1, n - 1) {
        per(j, n, i) dp[j] += dp[j - i];
    }
    printf("%lld\n", dp[n]);
}