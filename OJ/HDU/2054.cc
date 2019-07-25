#include <bits/stdc++.h>

#pragma comment(linker, “/STACK:1024000000,1024000000”)


using namespace std;

void trim0(string& s) {
    int len = s.length() - 1;
    if (s.find('.') != string::npos) {
        for(int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') len--;
        }
        s = s.substr(0, len);
    }
    if (s[len] == '.') {
        s = s.substr(0, len - 1);
    }
}

int main() {
    long long num[100010000];
    long long ldp[100010000];
    string s1, s2;
    while(cin >> s1 >> s2) {
        trim0(s1);
        trim0(s2);
        cout << s1 << " " << s2;
        if (s1 == s2) cout << "YES\n";
        else cout << "NO\n";
    }
    system("pause");
}