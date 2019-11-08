#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

char s1[210], s2[210], s3[410];
int dp[210][210];

int main() {
    int T = read();
    rep(kase, 1, T) {
        scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1), len3 = strlen(s3 + 1);
        rep(i, 1, len1) dp[i][0] = dp[i - 1][0] + (s1[i] == s3[i]);
        rep(i, 1, len2) dp[0][i] = dp[0][i - 1] + (s2[i] == s3[i]);
        rep(i, 1, len1) rep(j, 1, len2) {
            dp[i][j] = max(dp[i - 1][j] + (s1[i] == s3[i + j]), dp[i][j - 1] + (s2[j] == s3[i + j]));
        }
        printf("Data set %d:%s\n", kase, dp[len1][len2] == len3 ? "yes" : "no");
    }
}