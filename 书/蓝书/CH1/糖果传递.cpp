// link: https://www.acwing.com/problem/content/124/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 7;
int a[N], b[N];
int main() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum += a[i];
    }
    sum /= n;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i] - sum;
    }
    sort(b, b + n);
    ll med = b[n / 2];
    for (int i = 0; i < n; i++) {
        ans += abs(med - b[i]);
    }
    cout << ans << endl;
}