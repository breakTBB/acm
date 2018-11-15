#include <bits/stdc++.h>

using namespace std;

vector<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) q.push_back(i);
    int index = 0;
    while(q.size() != 1) {
        // 1 2 3 4 5 6 
        // m = 3
        index = (index + m - 1) % q.size();
        q.erase(q.begin() + index);
    }
    cout << q[0];
    system("pause");
}