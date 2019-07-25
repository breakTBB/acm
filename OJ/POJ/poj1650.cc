#include <bits/stdc++.h>

using namespace std;

double f;
int L;

int main() {
    cin >> f >> L;
    // cout << f << L;

    int ansn, ansd;
    int n = 1, d = 1;
    double min = 99999999, cha;
    while(n <= L && d <= L) {
        cha = f - (double)n / d;
        if (cha < min) {
            // 重点fabs
            min = fabs(cha);
            ansn = n;
            ansd = d;
        }
        if (cha > 0) n++;
        else d++;
    }
    cout << ansn << " " << ansd;
    system("pause");
}