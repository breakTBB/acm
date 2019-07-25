#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int pcount = 0;
    for(int i = 0; i < cnt; i++) {
        int tmp;
        int flag = true;
        cin >> tmp;
        for(int i = 2; i <= sqrt(tmp); i++) {
            if (tmp % i == 0) {
                flag = false;
            }
        }
        if (flag) pcount++;
    }
    cout << pcount;
    system("pause");
}