#include <bits/stdc++.h>

using namespace std;

int f[1010];
int ans[1010];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void join(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(ans, 0, sizeof ans);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) f[i] = i;
        while(m--) {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            ans[find(i)]++;
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] != 0) cnt++;
        }
        cout << cnt << endl;
    }
}
