// 把奇数留给后手

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int y, m, d;
        cin >> y >> m >> d;
        if ((m + d) % 2 == 0 || (d == 30 && (m == 9 || m == 11))) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
}