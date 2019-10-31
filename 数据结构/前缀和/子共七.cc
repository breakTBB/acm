#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 5e4 + 10;
int a[N], mod[10];

int main() {
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int ans = 0, pre = 0;
    rep(i, 1, n) {
        pre += a[i];
        pre %= 7;
        ans = max(ans, i - mod[pre]);
        if (!mod[pre]) mod[pre] = i;
    }
}