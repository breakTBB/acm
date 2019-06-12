// Maximum Multiple
// 数论 打表
// http://acm.hdu.edu.cn/showproblem.php?pid=6298


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if (n % 3 == 0) {
            cout << (n / 3) * (n / 3) * (n / 3) << endl;
        } else if (n % 4 == 0) {
            cout << (n / 4) * (n / 4) * (n / 2) << endl;
        } else {
            cout << -1 << endl;
        }

        // for (int n = 1; n <= 106; n++) {
        //     int mx = -1;
        //     int a, b, c;
        //     for (int i = 1; i <= n; i++) {
        //         for (int j = i; j <= n - i ; j++) {
        //             int k = n - i - j;
        //             if (k < j) break;
        //             if (n % i == 0 && n % j == 0 && n % k == 0) {
        //                 a = i; b = j; c = k;
        //                 mx = max(mx, i * j * k);
        //             }
        //         }
        //     }
        //     printf("n: %d max: %d a: %d b: %d c: %d\n", n, mx, a, b, c);
        // }
    }
}