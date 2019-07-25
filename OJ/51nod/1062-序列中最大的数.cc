#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];

int main(int argc, char const *argv[])
{
    a[0] = 0;
    b[0] = 0;
    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if(i & 1) a[i] = a[i / 2] + a[i / 2 + 1];
        else a[i] = a[i / 2];
        b[i] = max(b[i - 1], a[i]);
    }
    int T;
    cin >> T;
    while(T--) {
        int num;
        cin >> num;
        cout << b[num] << endl;
    }
    return 0;
}
