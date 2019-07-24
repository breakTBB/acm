// 带权并查集
// https://vjudge.net/problem/HDU-3172#author=0
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int id[maxn];
int ra[maxn];

void init() {
    for (int i = 1; i < maxn; ++i) {
        id[i] = i;
        ra[i] = 1;
    }
}

int find(int x) {
    return x == id[x] ? x : id[x] = find(id[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        id[x] = y;
        ra[y] += ra[x];
    }
    printf("%d\n", ra[y]);
}

int main() {
    int t, n;
    while(~scanf("%d", &t)) {
        string s1, s2;
        while(t--) {
            init();
            map<string, int> m;
            scanf("%d", &n);
            int k = 1;
            while(n--) {
                cin >> s1 >> s2;
                if (!m[s1]) m[s1] = k++;
                if (!m[s2]) m[s2] = k++;
                join(m[s1], m[s2]);
            }
        }
    }
    return 0;
}