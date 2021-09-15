#include <bits/stdc++.h>

using namespace std;

set<int> st;
int n, m;
char e[3][30];
int val[30], vis[30], q[30];

bool chk() {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int a = val[e[0][i] - 'A'], b = val[e[1][i] - 'A'], c = val[e[2][i] - 'A'];
        if (~a && ~b && ~c) {
            if (carry == -1) {
                if ((a + b + 1) % n != c && (a + b) % n != c) return false;
                if ((!i) && a + b >= n) return false;
            }
            else {
                if ((a + b + carry) % n != c || ((!i) && a + b + carry >= n)) return false;
                carry = (a + b + carry) / n;
            }
        }
        else {
            carry = -1;
        }
    }
    return true;
}

bool dfs(int cur) {
    if (cur == n) return chk();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            val[q[cur]] = i;
            if (chk() && dfs(cur + 1)) return true;
            vis[i] = 0;
            val[q[cur]] = -1;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> e[i];
    for (int i = n - 1, k = 0; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (!vis[e[j][i] - 'A']) {
                q[k++] = e[j][i] - 'A';
                vis[e[j][i] - 'A'] = true;
            }
        }
    }
    memset(vis, 0, sizeof vis);
    memset(val, -1, sizeof val);
    dfs(0);
    for (int i = 0; i < n; i++) cout << val[i] << ' ';
    return 0;
}