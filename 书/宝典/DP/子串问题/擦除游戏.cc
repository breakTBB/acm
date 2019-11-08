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
const int N = 1e3 + 10;
int score[300];
int dp[N][N];
char s1[N], s2[N];
char c;

int main() {
    int n = read();
    rep(i, 1, n) {
        cin >> c;
        score[c - 'a'] = read();
    }
    scanf("%s%s", s1 + 1, s2 + 1);
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    rep(i, 1, len1) {
        rep(j, 1, len2) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + score[s1[i] - 'a'];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[len1][len2]);
}