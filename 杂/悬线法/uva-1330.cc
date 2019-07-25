#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) {ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar();}
    return ret * f;
}

char mp[1010][1010];
int up[1010][1010], l[1010][1010], r[1010][1010];

int main() {
    int t = read();
    while(t--) {
        int ans = 0;
        int n = read(), m = read();
        rep(i, 1, n)
        rep(j, 1, m) {
            cin >> mp[i][j];
            l[i][j] = r[i][j] = j;
            up[i][j] = 1;
        }
        rep(i, 1, n) rep(j, 2, m) {if (mp[i][j] == 'F' && mp[i - 1][j - 1] == 'F') l[i][j] = l[i][j - 1]; }
        rep(i, 1, n) rep(j, m - 1, 1) {if (mp[i][j] == 'F' && mp[i - 1][j] == 'F') r[i][j] = r[i][j + 1]; }
        rep(i, 1, n) rep(j, 1, m) {
            if ((i ^1) && mp[i][j] == 'F' && mp[i - 1][j] == 'F') {
                l[i][j] = max(l[i][j], l[i - 1][j]), r[i][j] = min(r[i][j], r[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            ans = max(ans, (r[i][j] - l[i][j] + 1) * up[i][j]);
        }
        cout << ans * 3 << endl;
    }
}