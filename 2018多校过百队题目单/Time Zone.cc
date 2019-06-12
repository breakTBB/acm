#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; ++cas) {
        int sgn;
        int a, b, x, y(0);
        string s;
        cin >> a >> b >> s;
        sgn = (s[3] == '+' ? 1 : -1);
        s = s.substr(4);
        if (s.size() > 2) {
            y = s.back() - '0';
            s.pop_back();
            s.pop_back();
        }
        
        x = stoi(s);
        int delta = (sgn* (x * 10 + y) - 80) * 6;
        int m = (a * 60 + b) + delta;
        m %= 60 * 24;
        printf("%02d:%02d\n", m / 60, m % 60);
    }
}