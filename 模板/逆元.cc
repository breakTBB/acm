#include <bits/stdc++.h>

using namespace std;

void ex_gcd(int a, int b, int &x, int &y, int &d) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
    } else {
        ex_gcd(b, a % b, y, x, d);
        y -= a / b * x;
    }
}
int main() {
    int n, m, d, x, y;
    while(cin >> n >> m) {
        ex_gcd(n, m, x, y, d);
        cout << "x:" << x << " " << "y:" << y << endl;
        if (d != 1) cout << "No"<<endl;
        else cout << ((x  % m) + m ) % m << endl;
    }
}