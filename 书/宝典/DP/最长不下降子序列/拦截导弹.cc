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
vector<int> v, vv;
int a[1010], tot;

int main() {
    int t;
    while(cin >> t) a[++tot] = t;
    v.push_back(-inf);
    rep(i, 1, tot) {
        if (a[i] >= v.back()) v.push_back(a[i]);
        else *upper_bound(v.begin(), v.end(), a[i]) = a[i];
    }
    int x = v.size() - 1;
    v.clear();
    v.push_back(-inf);
    per(i, tot, 1) {
        if (a[i] >= v.back()) v.push_back(a[i]);
        else *upper_bound(v.begin(), v.end(), a[i]) = a[i];
    }
    int y = v.size() - 1;
    printf("%d %d", y, x);
}

// 389 207 155 300 299 170 158 65