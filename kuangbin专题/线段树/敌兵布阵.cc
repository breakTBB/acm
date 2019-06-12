// 线段树
// http://acm.hdu.edu.cn/showproblem.php?pid=1166

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 10;
using ll = long long;
int t[maxn << 2];
char op[20];
int val, ql, qr;
int a, b;

void build(int id, int l, int r) {
    if (l == r) {
        scanf("%d", &t[id]);
        return;
    }
    int m = (l + r) / 2;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

void update(int id, int l, int r) {
    if (l == r) {
        t[id] += val;
        return;
    }
    int mid = (l + r) /2 ;
    if (a <= mid) update(id << 1, l, mid);
    else update(id << 1 | 1, mid + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
} 

int query(int id, int l, int r) {
    if (qr < ql) return 0;
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return t[id];
    int mid = (l + r) / 2 ;
    return query(id << 1, l, mid) + query(id << 1 | 1, mid + 1, r);
}

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') {ret = ret * 10 + c - '0'; c = getchar();}
    return ret * f;
}

int main() {
    int cas = read();
    int c = 1;
    while(cas--) {
        memset(t, 0, sizeof t);
        int n = read();
        build(1, 1, n);
        cout << "Case " << c++ << ":" << endl;
        while(scanf("%s", op), op[0] != 'E') {
            scanf("%d%d", &a, &b);
            if (op[0] == 'Q') {
                ql = a;
                qr = b;
                cout << query(1, 1, n) << endl;
            } else if (op[0] == 'A') {
                val = b;
                update(1, 1, n);
            } else {
                val = -b;
                update(1, 1, n);
            }
        }
    }
}