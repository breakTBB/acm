#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 1e5 + 10;
int a[N];
map<int, int> cnt;

int main() {
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    ll ans = 0, pre = 0;
    cnt[0] = 1;
    rep(i, 1, n) {
        pre += a[i];
        pre %= k;
        ans += cnt[pre];
        cnt[pre]++;
    }
    cout << ans << endl;
}