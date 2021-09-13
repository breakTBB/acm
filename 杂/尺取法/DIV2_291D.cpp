#include <bits/stdc++.h>

#define fileio                                                  \
    freopen("C:\\Users\\PRISM17\\Desktop\\in.txt", "r", stdin); \
    freopen("C:\\Users\\PRISM17\\Desktop\\out.txt", "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define dbg(x) cout << #x << " : " << x << endl;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lson (id << 1)
#define rson (id << 1 | 1)
#define mid (st[id].l + st[id].r >> 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int INF = 1e9;

const int N = 1e5 + 7;
int d[6][N];
int cur[6];
multiset<int> mx[6];
void update(pii& ans, int l, int r) {
    if (r - l > ans.second - ans.first) ans.first = l, ans.second = r;
}
int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &d[j][i]);
        }
    }
    pii ans = {1, 0};
    int sum = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && sum <= k) {
            sum = 0;
            for (int co = 1; co <= m; co++) mx[co].insert(d[co][j]), cur[co] = max(cur[co], d[co][j]), sum += cur[co];
            if (sum <= k) {
                update(ans, i, j);
                ++j;
            } else {
                break;
            }
        }
        if (sum <= k) update(ans, i, j);
        sum = 0;
        for (int co = 1; co <= m; co++) {
            cur[co] = 0;
            if (!mx[co].empty()) {
                mx[co].erase(mx[co].find(d[co][i]));
                if (!mx[co].empty()) cur[co] = *--mx[co].end();
            }
            sum += cur[co];
        }
    }
    if (ans.first <= ans.second) {
        for (int i = 1, mxx = 0; i <= m; i++, mxx = 0) {
            for (int l = ans.first; l <= ans.second; l++) mxx = max(mxx, d[i][l]);
            printf("%d ", mxx);
        }
    } else {
        for (int i = 1; i <= m; i++) printf("0 ");
    }
}