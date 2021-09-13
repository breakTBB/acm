// link: https://www.acwing.com/problem/content/152/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 7;

const int N = 2500;
int c, l;
pii cow[N];
multiset<int> st;
int main() {
    cin >> c >> l;
    for (int i = 1; i <= c; i++) cin >> cow[i].first >> cow[i].second;
    for (int i = 1; i <= l; i++) {
        int x; cin >> x; int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            st.insert(x);
        }
    }
    sort(cow + 1, cow + c + 1);
    int ans = 0;
    for (int i = 1; i <= c; i++) {
        auto it = st.lower_bound(cow[i].first);
        if (it != st.end()) {
            ++ans;
            st.erase(it);
        }
    }
    cout << ans << endl;
}