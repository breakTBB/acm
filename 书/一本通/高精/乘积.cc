#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int pro[210];
string s1, s2;

int main() {
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sz1 = s1.size(), sz2 = s2.size();
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            pro[i + j] += (s1[i] - '0') * (s2[j] - '0');
            pro[i + j + 1] += pro[i + j] / 10;
            pro[i + j] %= 10;
        }
    }
    int now = 209;
    while(pro[now] == 0 && now != 0) now--;
    for (int i = now ; i >= 0; i--) cout << pro[i];
}