// n^n最后一位，等价于(n%100)^(n%100)的最后一位。


#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int lastd = n % 10;
        if (lastd == 1 || lastd == 5 || lastd == 6 || lastd == 0) {
            cout << lastd;
        }
        if (lastd == 2) {
            // 2 4 8 6 
            int num[] = {6, 2, 4, 8};
            cout << num[(n % 4)];
        }
        if (lastd == 3) {
            // 3 9 7 1 
            int num[] = {1, 3, 9, 7};
            cout << num[n % 4];
        }
        if (lastd == 4) {
            // 4 6
            int num[] = {6, 4};
            cout << num[n % 2];
        }
        if (lastd == 7) {
            // 7 9 3 1
            int num[] = {1, 7, 9, 3};
            cout << num[n % 4];
        }
        if (lastd == 8) {
            // 8 4 2 6
            int num[] = {6, 8, 4, 2};
            cout << num[n % 4];
        }
        if (lastd == 9) {
            // 9 1
            int num[] = {1, 9};
            cout << num[n % 2];
        }
        puts("");
    }
}