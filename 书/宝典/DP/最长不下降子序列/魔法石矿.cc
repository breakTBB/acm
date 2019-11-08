#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

int a[1010], dp[1010];
vector<int> from[1010];

int main() {
    string str;
    getline(cin, str);
    stringstream nin(str);
    int n; nin >> n;
    getline(cin, str);
    stringstream data(str);
    rep(i, 1, n) data >> a[i];
    
    rep(i, 1, n) {
        getline(cin, str);
        stringstream ss(str);
        int t;
        while(ss >> t) from[t].push_back(i);
    }
    int mx = 0;
    rep(i, 1, n) {
        dp[i] = a[i];
        for (auto k : from[i]) {
            if (k != i) dp[i] = max(dp[i], dp[k] + a[i]);
        }
        mx = max(mx, dp[i]);
    }
    printf("%d", mx);
}