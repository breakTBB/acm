#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> m;
    string s;
    while(getline(cin, s), s[0] != '\0') {
        int i = s.find(' ');
        string f = s.substr(0,i);
        string snd = s.substr(i+1);
        m[snd] = f;
    }

    while(cin >> s) {
        if (m[s] == "") cout << "eh" << endl;
        else cout << m[s] << endl;
    }
    system("pause");
    return 0;
}
