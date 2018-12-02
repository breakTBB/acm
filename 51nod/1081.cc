#include <bits/stdc++.h>

using namespace std;

const int N = 50010;
long long prefixsum[N+1];

int main() {
    ios::sync_with_stdio(false);
    int cnt, tmp;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        cin >> tmp;
        prefixsum[i] = prefixsum[i-1] + tmp;
    }
    int qry;
    cin >> qry;
    while(qry--) {
        int idx, len;
        cin >> idx >> len;
        cout << prefixsum[idx+len-1] - prefixsum[idx-1] << endl;
    }
    system("pause");
}