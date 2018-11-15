#include <bits/stdc++.h>

using namespace std;

map<string, int> d;
vector<int> q;

int main(int argc, char const *argv[])
{
    d["one"] = d["a"] = d["another"] = d["first"] = 1;
    d["two"] = d["both"] = d["second"] = 4;
    d["three"] = d["third"] = 9;
    d["four"] = 16;
    d["five"] = 25;
    d["six"] = 36;
    d["seven"] = 49;
    d["eight"] = 64;
    d["nine"] = 81;
    d["ten"] = 0;
    d["eleven"] = 21;
    d["twelve"] = 44;
    d["thirteen"] = 69;
    d["fourteen"] = 96;
    d["fifteen"] = 25;
    d["sixteen"] = 56;
    d["seventeen"] = 89;
    d["eighteen"] = 24;
    d["nineteen"] = 61;
    d["twenty"] = 0;

    string str;
    for(int i = 0; i < 6; i++) {
        cin >> str;
        //判断是否存在
        if(d.count(str)>0) q.push_back(d[str]);
    }
    sort(q.begin(), q.end());
    long long ans = 0;
    for(auto i : q) {
        ans = ans * 100 + i;
    }
    cout << ans;
    system("pause");
    return 0;
}
