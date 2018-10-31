// TODO: 
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> joseph(14, 0); //打表保存K对应的M
    int k;
    while(cin >> k) {
        if(!k) break;
        if(joseph[k]) {
            cout << joseph[k] << "\n";
            continue;
        }
        int n = k * 2;
        vector<int> ans = {0};
        int m = 1;
        for(int i = 1; i <= k; i++) {
            ans[i] = (ans[i - 1] + m - 1) % (n - i + 1);
            if(ans[i] < k) {
                i = 0;
                m++;
            }
        }
        joseph[k] = m;
        cout << m << "\n";
    }
    system("pause");
    return 0;
}
