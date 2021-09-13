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

int dp[50][10];
char str[50];
int n, k, num;

ll tonum(int st, int ed) {
    
}

int main() {
    n = read(), k = read();
    num = read();
    rep(i, 1, n) dp[i][0] = ;
    rep(i, 1, k) {
        rep(j, i + 1, n) {
            dp[j][i] = max(dp[j - 1][i], )
        }
    }
}