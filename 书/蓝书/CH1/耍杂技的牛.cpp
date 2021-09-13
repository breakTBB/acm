// link: https://www.acwing.com/problem/content/125/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n; cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](pii a, pii b) {return a.first + a.second < b.first + b.second;});
    ll ans = LONG_LONG_MIN, pre = 0;
    for (int i = 0; i < n; i++) {
        ans = max(pre - v[i].second, ans);
        pre += v[i].first;
    }
    cout << ans << endl;
}