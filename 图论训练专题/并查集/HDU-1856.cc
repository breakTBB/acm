#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 10;
int id[maxn];
int ran[maxn];

int mx = -1;

void init(int n) {
    mx = -1;
    for(int i = 1; i < n; i++) {
        id[i] = i;
        ran[i] = 1;
    }
}

int find(int x) {
    return x == id[x] ? x : id[x] = find(id[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    id[x] = y;
    ran[y] += ran[x];
    mx = max(mx, ran[y]);
}

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) {
            puts("1");
            continue;
        }
        init(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }
        cout << mx << endl;
    }
}