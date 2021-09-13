#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << x << endl;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define inf 0x3f3f3f3f
using namespace std;
 
struct node {
    int l, r, v;
    bool operator < (const node& rhs) {
        if (r != rhs.r) return r < rhs.r;
        return v < rhs.v;
    }
};
 
bool cmp(node a, node b) {
    if (a.l != b.l) a.l > b.l;
    return b.l > a.l;
}
const int N = 1e5 + 10;
node a[N];
int dp[N];
int n, k, l, r, v;
 
int main() {
    FASTIO;
    cin >> n >> k;
    rep(i, 1, k) {
        cin >> l >> r >> v;
        a[i] = {l, r, v};
    }
 
    int last = 1; bool f = true;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= k; i++) {
        if (a[i].l > last) {
            f = false;
            break;
        }
        last = max(last, a[i].r);
    }
    if (last < n || !f) {
        cout << "No" << endl;
        return 0;
    }
 
 
    sort(a + 1, a + n + 1);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
 
    rep(i, 1, k) {
        dp[a[i].r] = min(dp[a[i].l] + a[i].v, dp[a[i].r]);
    }
 
    puts("Yes");
    cout << dp[n] << endl;
}