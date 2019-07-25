#include <bits/stdc++.h>

using namespace std;

int E[20];
int D[20010];

struct P {
    int n1;
    int n2;
}p[20010];

bool cmp(P a, P b) {
    if (a.n2 != b.n2) return a.n2 > b.n2;
    else {
        return a.n1 < b.n1;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 10; i++) cin >> E[i];
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        p[i].n1 = i;
        p[i].n2 = t;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int tmp = E[(i - 1) % 10 + 1];
        p[i].n2 += tmp;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= k; i++) {
        cout << p[i].n1 << " ";
    }
    freopen("CON", "r", stdin);
    system("Pause");

}