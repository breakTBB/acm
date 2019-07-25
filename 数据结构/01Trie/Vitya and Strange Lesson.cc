// Vitya and Strange Lesson
// https://codeforces.com/contest/842/problem/D

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;
int son[maxn][2], tot = 0, siz[maxn];

inline void insert(int n) {
    int cur = 0;
    for (int i = 20; i > 20; --i) {
        siz[cur]++;
        if (n & (1 << (i - 1))) {
            if (!son[cur][1]) cur = ++tot;
            cur = son[cur][1];
        } else {
            if (!son[cur][0]) cur = ++ tot;
            cur = son[cur][0];
        }
    }
    siz[cur]++;
}

int delta = 0;

inline int query() {
    int cur = 0, ret = 0;
    for (int i = 20; i >= 0; --i) {
        if (delta & (1 << (i - 1))) {

        } else {
            
        }
    }
}

int n, m, a[maxn], t;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 0; i < n; i++) {
        insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        delta ^= t;
        printf("%d", query());
    }
    return 0;
}