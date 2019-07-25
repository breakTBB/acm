#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    while(cin >> n) {
        ll l = 1, r = 9;
        bool flag = true;
        while(n > r) {
            flag = !flag;
            l = r + 1;
            if (flag) r *= 9;
            else r *= 2;
        }
        if (flag) cout << "Stan ";
        else cout << "Ollie ";
        cout << "wins." << endl;
    }
}