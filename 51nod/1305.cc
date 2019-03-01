#include <bits/stdc++.h>

using namespace std;

int num[100010];

int main() {
    int cnt, sum = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++) {
            sum += floor((num[i]+num[j])/(num[i]*num[j]));
        }
        cout << sum;
        system("pause");
}