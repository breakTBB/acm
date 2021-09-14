#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\out.txt", "w", stdout);

const int inf = 0x3f3f3f3f;
const int N = 9;
char str[N * N + 1];
int st[N][N], st2[N * N][N][N], cnt[1 << N];
map<int, int> trans;

void put(int x, int y, int k) {
    for (int i = 0; i < N; i++) {
        st[x][i] &= ~(1 << k);
        st[i][y] &= ~(1 << k);
    }
    int xx = x / 3 * 3, yy = y / 3 * 3;
    for (int i = 0; i < N; i++) {
        int nx = xx + i / 3, ny = yy + i % 3;
        st[nx][ny] &= ~(1 << k);
    }
    st[x][y] = 1 << k;
}

bool dfs(int tot) {
    if (!tot) return true;
    memcpy(st2[tot], st, sizeof st);
    for (int i = 0; i < N * N; i++) {
        if (str[i] == '.') {
            if (cnt[st[i / N][i % N]] == 1) {
                int k = trans[st[i / N][i % N]];
                str[i] = char('0' + k);
                put(i / N, i % N, k);
                if (dfs(tot - 1)) return true;
                // !!!! 因为这一种情况其实也是 由错误的决策导致的，所以必须回溯 让之前的分支能够正确恢复状态
                str[i] = '.';
                memcpy(st, st2[tot], sizeof st);
                return false;
            }
            if (!st[i / N][i % N]) return false;
        }
    }
    int nx = -1, ny = -1;
    for (int i = 0; i < N * N; i++) {
        if (str[i] != '.') continue;
        if (nx == -1 || cnt[st[i / N][i % N]] < cnt[st[nx][ny]]) {
            nx = i / N;
            ny = i % N;
        }
    }
    assert(nx != -1);
    for (int i = 0; i < N; i++) {
        if (st[nx][ny] & (1 << i)) {
            str[nx * N + ny] = char('0' + i);
            put(nx, ny, i);
            if (dfs(tot - 1)) return true;
            str[nx * N + ny] = '.';
            memcpy(st, st2[tot], sizeof st);
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            st[i][j] = (1 << N) - 1;
        }
    }
    int tot = 0;
    for (int i = 0; i < N * N; i++) if (str[i] != '.') --str[i];
    for (int i = 0; i < N * N; i++) {
        if (str[i] == '.') ++tot;
        else put(i / N, i % N, str[i] - '0');
    }
    dfs(tot);
    for (int i = 0; i < N * N; i++) ++str[i];
    cout << str << endl;
}

int main() {
    // 该回溯的状态一定要回溯!!!
    for (int i = 0; i < (1 << N); i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (int i = 0; i < N; i++) trans[1 << i] = i;
    while (cin >> str) {
        if (!strcmp(str, "end")) break;
        solve();
    }
    return 0;
}
