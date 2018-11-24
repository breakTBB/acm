#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}


int main() {
    int cnt, tmp;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &tmp);
        if (isPrime(tmp)) puts("Yes");
        else puts("No");
    }
    system("pause");
}