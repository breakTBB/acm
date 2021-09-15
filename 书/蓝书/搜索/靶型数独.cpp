#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\PRISM17\\Desktop\\acm-training\\out.txt", "w", stdout);

const int inf = 0x3f3f3f3f;
const int N = 9;
int mp[N][N];
int st[N][N], cnt[1 << N];
map<int, int> trans;
int val[N][N];
int ans;

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

bool dfs(int tot, int pts) {
    if (!tot) {
        ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += (mp[i][j] + 1) * val[i][j];
            }
        }
        return true;
    }
    int st2[N][N]{};
    memcpy(st2, st, sizeof st);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == -1) {
                if (cnt[st[i][j]] == 1) {
                    int k = trans[st[i][j]];
                    mp[i][j] = k;
                    put(i, j, k);
                    if (dfs(tot - 1, pts + val[i][j] * (k + 1))) return true;
                    mp[i][j] = -1;
                    memcpy(st, st2, sizeof st);
                    return false;
                }
                if (!st[i][j]) return false;
            }
        }
    }
    int nx = -1, ny = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == -1 && (nx == -1 || val[i][j] > val[nx][ny] || (val[i][j] == val[nx][ny] && cnt[st[i][j]] < cnt[st[nx][ny]]))) nx = i, ny = j;
        }
    }
    assert(nx != -1);
    assert(mp[nx][ny] == -1);
    for (int i = N - 1; i >= 0; i--) {
        if (st[nx][ny] & (1 << i)) {
            mp[nx][ny] = i;
            put(nx, ny, i);
            if (dfs(tot - 1, pts + (i + 1) * val[nx][ny])) return true;
            mp[nx][ny] = -1;
            memcpy(st, st2, sizeof st);
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mp[i][j];
            --mp[i][j];
            if (mp[i][j] >= 0) put(i, j, mp[i][j]);
            else ++tot;
        }
    }
    dfs(tot, 0);
    cout << ans << endl;
}

int d[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int main() {
    for (int i = 0, x = 0, y = 0, k = 0, pts = 6; i < N * N; i++) {
        if (x < 0 || x >= N || y < 0 || y >= N || val[x][y]) {
            x -= d[k][0]; y -= d[k][1];
            if (++k == 4) ++pts, k = 0;
            x += d[k][0]; y += d[k][1];
        }
        val[x][y] = pts;
        x = x + d[k][0], y = y + d[k][1];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(2) << val[i][j] << " \n"[j == N - 1];
        }
    }
    for (int i = 0; i < (1 << N); i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (int i = 0; i < N; i++) trans[1 << i] = i;
    solve();
    return 0;
}