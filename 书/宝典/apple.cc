#include <bits/stdc++.h>

using namespace std;


int cnt;
int aa[100] = {1};
void split(int a, int last, int b) {
    if (last == 1&&b >= aa[a - 1]) {
        aa[a] = b;
        for (int i = 1; i <= a; i++) {
            cout << aa[i] << " ";
        }
        cout << endl;
        cnt++;
        return;
    } else {
        for (int i = aa[a - 1]; i <= b / last; i++) {
            aa[a] = i;
            split(a + 1, last - 1, b - i);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        memset(aa, 0, sizeof(aa));
        aa[0] = 1;
        int m, n;
        cin >> m >> n;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        split(1, i, m);
        cout << cnt;
    }
    system("pause");

}