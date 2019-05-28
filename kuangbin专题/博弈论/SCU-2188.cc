#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n;
    while(cin >> n) {
        ll l = 1, r = 9;
        bool flag = true;
        while (r < n) {
            flag = !flag;
            l = r + 1;
            if (flag) r *= 9;
            else r *= 2;
        }
        if (flag) cout << "Stan wins.\n";
        else cout << "Ollie wins.\n";
    }
}