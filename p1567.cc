#include <bits/stdc++.h>

using namespace std;
int t[10000010];


int main() {
    freopen("input.txt","r",stdin);
    t[0] = -9999999;
    int cnt;
    int persist = 0;
    int maxp = 0;
    cin >> cnt;
    for(int i = 1; i <= cnt; i++) {
        scanf("%d",&t[i]);
        if(t[i]>t[i-1]) {
            persist++;
        } else {
            persist = 1;
        }
        if(persist>maxp)maxp = persist;
    }
    cout << maxp;
    freopen("CON","r",stdin);
    system("pause");
}