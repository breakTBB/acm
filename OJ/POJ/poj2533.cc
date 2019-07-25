#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    vector<int> n(cnt);
    for(int i = 0; i < cnt; i++) cin >> n[i];
    // for(auto i : n) cout << i;
    vector<int> dp(cnt);
    fill(dp.begin(),dp.end(),1);
    for(int i = 0; i < cnt; i++) {
        int left = i - 1;
        int maxn = 0;
        while(left >= 0) {
            if(n[left] < n[i]) {
                maxn = max(maxn, dp[left]);
            }
            left--;
        }
        dp[i] = maxn + 1;
        cout << "dp[" << i << "]=" << dp[i] << " ";
        
    }
    cout << *max_element(dp.begin(), dp.end());

    system("pause");
    return 0;
}
