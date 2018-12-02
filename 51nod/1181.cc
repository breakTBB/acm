#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
bool p[maxn<<1];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i < maxn; i++) {
        if(!p[i]) {
            cnt++;
            if(!p[cnt] && i >= n) {
                cout << i << endl;
                break;
            }
            for (int j = i+i; j < maxn; j+=i) {
                p[j] = true;
            }
        }
    }
    system("pause");
}