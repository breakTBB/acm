#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> num;
    string str;
    int tmp;cin>>tmp;
    while(cin >> str) {
        if ('0' == str[0]) {
            int n;
            cin >> n;
            num.push_back(n);
        } 
        else if ('1' == str[0]) {
            int idx;
            cin >> idx;
            cout << num[idx] << endl;
        }
        else {
            num.pop_back();
        }
    }
    system("pause");
    return 0;
}
