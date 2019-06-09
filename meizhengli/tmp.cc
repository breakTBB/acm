#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int ans = 0;
        int len = str.length();
        for (register int i = 0; i < len; i++) {
            ans = (ans * 10 + (str[i] - '0')) % 9;
        }
        cout << ans << endl;
    }
}