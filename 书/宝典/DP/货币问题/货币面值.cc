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

int dp[10010];
int a[110];

int main() {
    int n, out;
    while(cin >> n) {
        rep(i, 1, n) a[i] = read();
        dp[0] = 1;
        rep(i, 1, n) {
            if (a[i] > dp[i - 1]) {
                out = dp[i - 1];
                break;
            } else {
                dp[i] = dp[i - 1] + a[i];
            }
        }
        if (!out) out = dp[n];
        printf("%d\n", out);
    }
    
}