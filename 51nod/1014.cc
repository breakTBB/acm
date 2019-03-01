#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    int p, a;
    bool flag = true;
    LL x;
    cin >> p >> a;
    for (x = 0; x <= p; x++) {
        if (x * x % p == a) {
            cout << x << ' ';
            flag = false;
        }
    }
    if (flag) cout << "No Solution";
    system("pause");
}