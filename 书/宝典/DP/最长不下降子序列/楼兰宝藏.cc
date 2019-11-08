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

vector<pair<int, int>> v;
vector<int> st;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    st.push_back(-inf);
    for (auto it : v) {
        if (it.second > st.back()) st.push_back(it.second);
        else *upper_bound(st.begin(), st.end(), it.second) = it.second;
    }
    printf("%d\n", st.size() - 1);
}