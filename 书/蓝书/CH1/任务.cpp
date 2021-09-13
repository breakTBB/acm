// link: https://www.acwing.com/problem/content/152/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 7;
int n, m;
multiset<int> st;
pii M[N], T[N];
ll get(pii x) {
    return 500 * x.first + 2 * x.second;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> M[i].first >> M[i].second;
    for (int i = 1; i <= m; i++) cin >> T[i].first >> T[i].second;
    sort(M + 1, M + n + 1); sort(T + 1, T + m + 1);
    ll ans = 0, cnt = 0;
    for (int i = m, j = n; i >= 1; i--) {
        while (j >= 1 && M[j].first >= T[i].first) {
            st.insert(M[j--].second);
        }
        auto it = st.lower_bound(T[i].second);
        if (it != st.end()) {
            ++cnt;
            ans += get(T[i]);
            st.erase(it);
        }
    }
    cout << cnt << ' ' << ans << endl;
}