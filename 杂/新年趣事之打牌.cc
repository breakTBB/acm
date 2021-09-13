#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
int f[N] = {0}, path[N], a[110];
int n, total, sum = 0, res;

void print(int url) {
    if (url) {
        print(url - a[path[url]]);
        if (url == res) {
            cout << path[url] << endl;
        } else {
            cout << path[url] << ' ';
        }
    }
}
int main() {
    cin >> total >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum == a[i];
    }
    f[0] = 1;
    res = sum - total;
    for (int i = 1; i <= n; i++) {
        for (int j = res; j >= a[i]; j--) {
            f[j] += f[j - a[i]];
            f[j] %= 100;
            if (!path[j] && f[j - a[i]]) {
                path[j] = i;
            }
        }
    }
    if (!f[res]) {
        cout << 0 << endl;
    } else if (f[res] > 1) {
        cout << -1 << endl;
    } else {
        print(res);
    }
    return 0;
}