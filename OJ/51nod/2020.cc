#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int n, k, len = 4, foo;
        cin >> n >> k;
        if (k == 0) {
            cout << n << endl;
            continue;
        }
        int ans = 0;
        char str[5];
        sprintf(str, "%d", n);
        int t1, t2;
        while (k--) {
            sort(str, str+len, greater<int>());
            sscanf(str, "%d", &t1);
            sort(str, str+len, less<int>());
            sscanf(str, "%d", &t2);
            n = abs(t1 - t2);
            foo = n;
            len = 0;
            while (n > 0) {
                len++;
                n /= 10;
            }
            sprintf(str, "%d", foo);
            for (int i = len; i < 5; i++) str[i] = ' ';
        }
        cout << foo << endl;
    }
    system("pause");
}