#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl;

using namespace std;
const int N = 1e5 + 10;
int cnt = 0;
int fa[N];

void init() {
    rep(i, 0, N - 1) fa[i] = i;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void join(int x, int y) {
    int tx = find(x), ty = find(y);
    if (tx != ty) {
        fa[tx] = ty;
    }
}

bool con(int x, int y) {
    return find(x) == find(y);
}

int main() {
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        
    }
}