#include <bits/stdc++.h>

using namespace std;
int apple[10];
int height;
int main() {
    // freopen("input.txt","r",stdin);
    for(int i = 0; i < 10; i++) {
        scanf("%d", &apple[i]);
    }
    scanf("%d", &height);
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        if(height+30>=apple[i])cnt++;
    }
    printf("%d", cnt);
}