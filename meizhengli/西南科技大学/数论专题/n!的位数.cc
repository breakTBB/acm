#include <bits/stdc++.h>

using namespace std;

int a[10010];
int p[10010];

int ans;

int main() {
    // ios::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            // if (a[i] % n == 0) {
            //     cout << 1 <<endl;
            //     cout << a[i] << endl;
            //     goto nex;
            // }
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) p[i] = a[i] + p[i - 1];
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((p[j] - p[i]) % n == 0) {
                    cout << j - i <<endl;
                    for (int x = i + 1; x <= j; ++x) {
                        cout << a[x] << " ";
                    }
                    cout << endl;
                }
            }
        }
        // nex:
    }
}