#include <bits/stdc++.h>

using namespace std;

map<string, string> user;

int main() {
    int cnt;
    cin >> cnt;
    while(cnt--) {
        string name;
        string time;
        if(name[0]=='s') {
            user[name] = time;
        }
        sort(user);
        
    }
}