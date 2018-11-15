#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    while(cnt--) {
        string str;
        cin >> str;
        str = str.substr(6);
        cout << 6 << str << endl;
    }
    system("pause");
    return 0;
}
