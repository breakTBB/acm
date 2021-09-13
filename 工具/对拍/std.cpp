#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], p[N], f[N], q = 0;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) scanf("%d", &a[i]), b[a[i]]++;
    for (int i = 1;i <= n;i++) {
        b[a[i]]--;
        if (!f[a[i]]) {
            while (a[i] < p[q] && b[p[q]]) f[p[q--]] = 0;
            f[a[i]] = 1, p[++q] = a[i];
        }
    }
    for (int i = 1;i <= q;i++) printf("%d ", p[i]);
}