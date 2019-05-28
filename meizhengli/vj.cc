#include <bits/stdc++.h>

using namespace std;

string dontuse[] = {
"void", "signed", "unsigned","short", "long","int","float","double",
"char","enum","struct","union","typedef","_Bool","_Imaginary","_Complex",
"const","volatile" ,"restrict","inline",
"auto","static","extern","register","sizeof","goto","return",
"break","continue","if","else","switch","case","default","do","while","for"};

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    getchar();
    for (int i = 0; i < cnt; i++) {
        string s;
        bool flag = true;
        getline(cin, s);
        char chr = s[0];
        if (!isalpha(chr) && chr != '_') {
            flag = false;
        }
        for (int i = 1; i < s.size(); i++) {
            if ((!isalpha(s[i])&&!isdigit(s[i])&&s[i]!='_')||s[i]==' ') {
                flag = false;
            }
        }
        for (auto ik : dontuse) {
            if (s == ik) {
                flag = false;
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    system("pause");
    return 0;
}
