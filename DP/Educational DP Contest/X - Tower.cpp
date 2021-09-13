// link: https://atcoder.jp/contests/dp/tasks/dp_x
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 7, M = 2e4 + 7;
ll dp[M];

struct node {
    ll w, s, v;
    bool operator < (const node& rhs) {
        return w + s < rhs.w + rhs.s;
    }
}a[N];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = a[i].s; j >= 0; j--) {
            dp[j + a[i].w] = max(dp[j] + a[i].v, dp[j + a[i].w]);
        }
    }
    ll ans = 0;
    for (int j = 0; j < M; j++) ans = max(dp[j], ans);
    cout << ans << endl;
}