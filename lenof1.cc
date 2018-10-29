#include <bits/stdc++.h>

int lenof1(int num) {
    int cnt = 0;
    while(num > 0) {
        cnt++;
        num >>= 1;
    }
    return cnt;
}

int main() {
    int n = 5;
    printf("%d", lenof1(7));
    system("pause");
}