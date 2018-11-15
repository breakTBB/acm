#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, t;
    string name;
    queue<pair<string, int>> Q;

    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    //模拟
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        // 执行时间片q或所需时间u, t的处理
        a = min(u.second, q);
        // 剩余所需时间
        u.second -= a;
        // 累计已过时间
        elaps += a;
        if( u.second > 0) {
            Q.push(u);
        } else {
            cout << u.first << " " << elaps << endl;
        }
    
    }



}