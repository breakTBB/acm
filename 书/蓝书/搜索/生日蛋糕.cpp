#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << endl;

using namespace std;
const int inf = 0x3f3f3f3f;
const int M = 21;
int n, m, ans = inf;
int mnv[M], mns[M];

void dfs(int depth, int r, int h, int s, int v) {
    if (!depth) {
        if (!v) ans = min(ans, s);
        return;
    }

    if (s + mns[depth] >= ans) return;
    if (v < mnv[depth]) return;
    int boundR = min((int)sqrt(v), r - 1);
    for (int R = boundR; R >= depth; R--) {
        int boundH = min((int)(1.0 * v / (R * R)), h - 1);
        for (int H = boundH; H >= depth; H--) {
            if (depth > 1 && 2 * v / R + s > ans) continue;
            dfs(depth - 1, R, H, s + 2 * R * H + (depth == m ? R * R : 0), v - R * R * H);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < M; i++) {
        mnv[i] = mnv[i - 1] + i * i * i;
        mns[i] = mns[i - 1] + 2 * i * i;
    }
    dfs(m, inf, inf, 0, n);
    if (ans == inf) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}