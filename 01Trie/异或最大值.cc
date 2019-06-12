#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int N, son[maxn][2], a[maxn], tot;

void init() {
    memset(son, 0, sizeof son);
    tot = 0;
}

void insert(int x) {
    int cur = 0;
    for (int i = 30; i >= 0; --i) {
        bool next = x & (1 << i);
        if (!son[cur][next]) son[cur][next] = ++tot;
        cur = son[cur][next];
    }
}

int query(int x) {
    int cur = 0, ret = 0;
    for (int i = 30; i >= 0; --i) {
        bool next = x & (1 << i) ^ 1;
        if (!son[cur][next]) ret |= (1 << i), cur = son[cur][next];
        else cur = son[cur][next ^ 1];
    }
    return ret;
}

int main() {
    int mx = INT_MIN;
    int n;
    cin >> n;
    vector<int> vi;
    for (int i = 0; i < n; i++) {
        cin >> vi[0];
        insert(vi[0]);
    }
    for (int i = 0; i < n; ++i) {
        mx = max(mx, query(vi[i]));
    }
    cout << mx << endl;
}