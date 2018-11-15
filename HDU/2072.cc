#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    while(getline(cin, s)) {
        set<string> dict;
        if (s[0] == '#') break;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            dict.insert(word);
        }
        cout << dict.size() << endl;
    }
    system("pause");
    return 0;
}
