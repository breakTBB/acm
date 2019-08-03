#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int a[N], b[N], n;


int main() {
    scanf("%d", &n);
    for (int i = 1; i <=n ; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int num = unique(b + 1, b + n + 1) - b;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
    for (int i = 1; i <= n; i++) printf("%d ", b[a[i]]);
}