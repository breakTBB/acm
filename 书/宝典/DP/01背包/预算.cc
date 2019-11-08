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

const int N = 4e3 + 10;
int MW[N], MV[N], AW[N][3], AV[N][3], lk[N], dp[N];

int main() {
    int m = read(), n = read();
    m /= 10;
    rep(i, 1, n) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (!z) {
            MW[i] = x / 10, MV[i] = y;
        } else {
            ++lk[z];
            AW[z][lk[z]] = x / 10, AV[z][lk[z]] = y;
        }
    }
    rep(i, 1, n) {
        if (MW[i]) {
            per(j, m, MW[i]) {
                dp[j] = max(dp[j], dp[j - MW[i]] + MW[i] * MV[i]);
                if (lk[i] >= 1 && j >= MW[i] + AW[i][1]) dp[j] = max(dp[j], dp[j - MW[i] - AW[i][1]] + MW[i] * MV[i] + AW[i][1] * AV[i][1]);
                if (lk[i] == 2 && j >= MW[i] + AW[i][1] + AW[i][2]) dp[j] = max(dp[j], dp[j - MW[i] - AW[i][1] - AW[i][2]] + MW[i] * MV[i] + AW[i][1] * AV[i][1] + AW[i][2] * AV[i][2]);
            }
        }
    }
    printf("%d\n", dp[m] * 10);
}