#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    while(cnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int m = min(a, b);
        int M = a + b - m;
        double t = M - m;
        if((int)(t * (sqrt(5.0) + 1.0)/2.0) - m == 0) printf("B\n");
        else printf("A\n");
    }
}