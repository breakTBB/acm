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
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

const int N = 1e6;

int main() {
    int n =read();
    int ans = -inf, sum = 0;
    rep(i, 1, n) {
        int t; scanf("%d", &t);
        sum += t;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    printf("%d", ans);
}