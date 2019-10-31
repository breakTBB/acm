#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 200;
int nxt[N];

int main() {
    int n, m;
    cin >> n;
    m = 3;
    int ans = 0;
    rep(i, 1, n - 1) nxt[i] = i + 1;
    nxt[n] = 1;
    int now = n;
    rep(i, 1, n) {
        rep(j, 1, m - 1) {
            now = nxt[now];
        }
        ans = nxt[now];
        nxt[now] = nxt[nxt[now]];
    }
    cout << ans << endl;
}