#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

const int N = 1e6 + 10;
vector<string> strs;
map<string, bool> vis;
int f[N];

int main() {
    f[0] = 1;
    string str;
    while(cin >> str, str != ".") {
        vis[str] = 1;
    }
    string temp = "", tmp;
    while(cin >> tmp) temp += tmp;
    int sz = temp.size();
    for (int i = 1; i <= sz; i++) {
        for (int j = i; j >= 1; j--) {
            if (f[j - 1] && vis[temp.substr(j - 1, i - j + 1)]) {
                f[i] = 1;
                break;
            }
        }
    }
    for (int i = sz; i >= 0; i--) if (f[i]) return 0 * printf("%d\n", i);
}