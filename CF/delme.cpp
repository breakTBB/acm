#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, k;
int num[12], tot;
int memo[12][2][2][2][2][2];

int dfs(int cur, int pre, int prepre, int f, int mg, int g) {
   int& val = memo[cur][pre][prepre][f][mg][g];
   if (val != -1) return val;
   if (cur == tot + 1) return mg;
   int UP = (f ? num[cur] : 9);
   int ans = 0;
   for (int i = 0; i <= UP; i++) {
      if (g) {
         if (i == 0) {
            ans += dfs(cur + 1, prepre, 0, f & (i == UP), 0, 0);
         }
         else {
            ans += (cur + 1, prepre, i, f & (i == UP), mg | (i == 6 && pre == 6 && prepre == 6), 0);
         }
      }
      else {
         ans += dfs(cur + 1, prepre, i, f & (i == UP), mg | (i == 6 && pre == 6 && prepre == 6), 0);
      }
   }
   val = ans;
   return ans;
}

bool chk(long long x) {
   memset(memo, -1, sizeof memo);
   tot = 0;
   while (x) {
      num[++tot] = x % 10;
      x /= 10;
   }
   reverse(num + 1, num + tot + 1);
   return dfs(1, 0, 0, 1, 0, 0) >= k;
}

int main() {
   freopen("in.txt", "r", stdin);
   cin >> t;
   while (t--) {
      cin >> k;
      long long l = 1, r = 1e10;
      while (l < r) {
         long long mid = (l + r) / 2;
         if (chk(mid)) r = mid;
         else l = mid + 1;
      }
      cout << l << endl;
   }
}
