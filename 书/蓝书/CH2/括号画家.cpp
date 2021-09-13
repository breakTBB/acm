// link: https://www.acwing.com/problem/content/152/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool check(char a, char b) {
    if (a == '(') return b == ')';
    if (a == '{') return b == '}';
    return b == ']';
}
const int N = 1e5 + 7;
int dp[N];
int main() {
    string str; cin >> str;
    vector<pair<char, int>> stk;
    for (int i = 0, n = str.length(); i < n; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push_back({ ch, i });
        }
        else {
            if (stk.size() && check(stk.back().first, ch)) {
                dp[i] = i - stk.back().second + 1;
                stk.pop_back();
            }
            else {
                stk.push_back({ ch, i });
            }
        }
    }
    int ans = 0;
    for (int i = 0, n = str.length(); i < n; i++) {
        if (i - dp[i] >= 0) dp[i] += dp[i - dp[i]];
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}