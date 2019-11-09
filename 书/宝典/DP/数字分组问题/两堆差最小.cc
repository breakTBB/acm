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
const int N = 1e5 + 10;
int dp[N], a[40];

int main() {
    int n = read();
    int sum = 0;
    rep(i, 1, n) a[i] = read(), sum += a[i];
    rep(i, 1, n) {
        per(j, sum / 2, a[i]) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    printf("%d\n", abs(sum - 2 * dp[sum / 2]));
}