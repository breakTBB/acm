#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    while(cnt--) {
        LL n, m;
        cin >> n >> m;
        if (__gcd(n, m) == 1) printf("NO\n");
        else printf("YES\n");
    }    
    return 0;
}
