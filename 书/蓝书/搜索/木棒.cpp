#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\out.txt", "w", stdout);


const int inf = 0x3f3f3f3f;


const int N = 64;
int n, len, a[N], b[N], v[N];

bool dfs(int cur, int sum, int pre) {
    if (cur == n) {
        return sum == len;
    }
    if (sum == len) return dfs(cur, 0, 1);
    int fail = 0;
    for (int i = pre; i <= n; i++) {
        if (a[i] + sum <= len) {
            if (!v[i] && a[i] != fail) {
                v[i] = 1;
                if (dfs(cur + 1, sum + a[i], i)) return true;
                else fail = a[i];
                v[i] = 0;
                if (!sum || sum + a[i] == len) return false;
            }
        }
    }
    return false;
}

int main() {
    FIN; FOUT;
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1, greater<>());
        int sum = accumulate(a + 1, a + n + 1, 0);
        int mx = *max_element(a + 1, a + n + 1);
        int ans = 0;
        for (len = mx; len <= sum; ++len) {
            if (sum % len) continue;
            memset(v, 0, sizeof v);
            if (dfs(0, 0, 1)) {
                ans = len;
                break;
            }
        }
        assert(ans != 0);
        cout << ans << endl;
    }
}