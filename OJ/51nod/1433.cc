#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL num0 = 0;
    LL num5 = 0;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) num0++;
        else num5++;
    }
    if (num0 == 0) {
        cout << -1;
        return 0;
    }
    num5 /= 9;
    for (int i = 1; i <= num5; i++) {
        for (int i = 1; i <= 9; i++) cout << 5;
    }
    if(num5==0) cout << 0;
    else for (int i = 1; i <= num0; i++) cout << 0;
    system("pause");
}
