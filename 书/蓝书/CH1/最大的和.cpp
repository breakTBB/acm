// link: https://www.acwing.com/problem/content/125/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 110;
int n;
int a[N][N], s[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + a[i][j];
        }
    }
    ll ans = LONG_LONG_MIN;
    for (int u = 1; u <= n; u++) {
        for (int b = u; b <= n; b++) {
            ll sum = 0, mx = LONG_LONG_MIN;
            for (int j = 1; j <= n; j++) {
                sum += s[b][j] - s[u - 1][j];
                mx = max(sum, mx);
                if (sum < 0) sum = 0;
            }
            ans = max(mx, ans);
        }
    }
    cout << ans << endl;
}