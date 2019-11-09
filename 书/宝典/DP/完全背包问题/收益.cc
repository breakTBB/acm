#include <iostream>
#include <cstring>
#include <cstdio>
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

int W[20], V[20];
int dp[50010];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T = read();
    while(T--) {
        memset(dp, 0, sizeof dp);
        int m = read(), year = read();
        int n = read();
        rep(i, 1, n) W[i] = read(), W[i] /= 1000, V[i] = read();
        rep(y, 1, year) {
            memset(dp, 0, sizeof dp);
            int mm = m / 1000;
            rep(i, 1, n) rep(j, W[i], mm) {
                dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
            }
            m += dp[mm];
        }
        printf("%d\n", m);
    }
}