#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

vector<int> v;

int main() {
    int n = read();
    v.push_back(-inf);
    rep(i, 1, n) {
        int t = read();
        if (t >= v.back()) {
            v.push_back(t);
        } else {
            auto it = upper_bound(v.begin(), v.end(), t);
            *it = t;
        }
    }
    printf("%d\n", v.size() - 1);
}