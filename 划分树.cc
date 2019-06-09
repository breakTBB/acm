#include <bits/stdc++.h>

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') {ret = ret * 10 + c - '0'; c = getchar();}
    return ret * f;
}
const int maxn = 1e6 + 10;
int a[maxn];
int b[maxn];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int t;
        t = read();
        a[i] = t;
    }
    while(q--) {
        int x = read(), y = read(), z = read();
        int idx = 1;
        while(x <= y) {
            b[idx++] = a[x++];
        }
        nth_element(b + 1, b + z, b + y - x + 2);
        cout << b[z] << endl;
    }

}