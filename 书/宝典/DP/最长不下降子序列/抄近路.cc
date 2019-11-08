#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

const int N = 1010;
int dp[N];
pii a[N];

int main() {
    int n = read(), m = read(), k = read();
    rep(i, 1, k) a[i].first = read(), a[i].second = read();
    sort(a + 1, a + k + 1);
    int mx = 0;
    rep(i, 1, n) {
        dp[i] = 1;
        rep(j, 1, i - 1) {
            if (a[i].first != a[j].first && a[j].second < a[i].second) dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }
    printf("%d", (int)((n - mx + m - mx) * 100 + round(sqrt(20000) * mx)));
}