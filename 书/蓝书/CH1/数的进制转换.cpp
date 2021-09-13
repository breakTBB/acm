// link: https://www.acwing.com/problem/content/125/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll num = 0, basein = 0, baseout = 0;

ll getval(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    return ch - 'a' + 36;
}
char getch(ll val) {
    if (val >= 0 && val <= 9) return '0' + val;
    if (val >= 10 && val <= 35) return 'A' + val - 10;
    return 'a' + val - 36;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string str;
        cin >> basein >> baseout >> str;
        vector<int> num;
        // reverse(str.begin(), str.end());
        for (int i = 0, n = str.length(); i < n; i++) {
            num.push_back(getval(str[i]));
        }
        vector<int> res;
        while (num.size()) {
            int r = 0;
            for (int i = 0, n = num.size(); i < n; i++) {
                r = r * basein + num[i];
                num[i] = r / baseout;
                r = r % baseout;
            }
            while (!num.empty() && num.back() == 0) num.pop_back();
            res.push_back(r);
        }
        string out;
        reverse(res.begin(), res.end());
        for (auto x : res) {
            out.push_back(getch(x));
        }
        cout << basein << ' ' << str << "\n";
        cout << baseout << ' ' << out << "\n\n";
    }
}