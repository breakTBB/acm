#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, flag = 0, stone;
    printf("%d", &m);
    while(m--) {
        scanf("%d", &stone);
        flag ^= stone;
    }
    printf("%c\n", flag == 0 ? 'B' : 'A');
}