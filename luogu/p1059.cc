#include <bits/stdc++.h>

using namespace std;

int n[110];
int nn[110];

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i++) cin >> n[i];
    sort(n, n+cnt);
    int last = 99999;
    int ans = 0;
    for(int i = 0; i < cnt; i++) {
        if(n[i] != last) {
            nn[ans++] = n[i];
        }
        last = n[i];
    }
    cout << ans << "\n";
    for(int i = 0; i < ans; i++) {
        cout << nn[i] << " ";
    }
    system("pause");
    return 0;
}
