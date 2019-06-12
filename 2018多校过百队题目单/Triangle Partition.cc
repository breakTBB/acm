#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 7;

struct node {
    int x, y, num;
    node(int x, int y, int num): x(x), y(y), num(num){}
    node(){}
    bool operator < (const node &o) const {
        return x <o.x || x == o.x && y < o.y;
    }
} a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 3 * n; i++) {
            int x, y;
            cin >> a[i].x >> a[i].y;
            a[i].num =i + 1;
        }
        sort(a, a + 3*n);
        int ttt = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            printf("%d %d %d\n", a[j].num, a[j + 1].num, a[j + 2].num);
            j += 3;
        }
    }
}