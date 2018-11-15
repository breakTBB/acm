#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n, cnt = 0;
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++) {
        int num = i;
        while(num != 0) {
            int tmp = num % 10;
            num /= 10;
            if(tmp == x)cnt++;
        }
    }
    printf("%d",cnt);
}