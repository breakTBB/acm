#include <bits/stdc++.h>

using namespace std;

const int N = 18;
int a[N], b[N + 1];
int n, w, ans = 0x3f3f3f3f;

void dfs(int cur, int g) {
    if (cur == n) {
        ans = min(g, ans);
        return;
    }
    if (g > ans) return;
    for (int i = 0; i < g; i++) {
        if (a[cur] + b[i] <= w) {
            b[i] += a[cur];
            dfs(cur + 1, g);
            b[i] -= a[cur];
        }
    }
    b[g] += a[cur];
    dfs(cur + 1, g + 1);
    b[g] -= a[cur];
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<>());
    dfs(0, 0);
    cout << ans << endl;
}