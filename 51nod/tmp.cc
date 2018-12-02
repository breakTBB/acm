#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, v, l, r;
    int cnt;
    int ans;
    scanf("%d", &cnt);
    while(cnt--) {
        ans = 0;
        scanf("%d%d%d%d", &L, &v, &l, &r);
        for(int i = v; i <= L; i+=v) {
            if (i<l||i>r) ans++;
        }
        printf("%d\n", ans);
    }
    system("pause");
}