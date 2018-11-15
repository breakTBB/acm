#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int m, n;
    cin >> n >> m;
    if(0 == m && 0 == n) return 0;
    for(int i = 1; i <= n; i++) v.push_back(i);
    int index = 0;
    while(v.size() != 1) {
        index = (index + m - 1) % v.size();
        cout << v.at(index) << " ";
        v.erase(v.begin() + index);
    }
    cout << v[0];
    system("pause");
}