#include <bits/stdc++.h>

using namespace std;
int num[10010];
int ans[10010];
int main() {
    int cnt;
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < cnt; i++) {
        int beauty = 0;
        int left = i - 1;
        while(left>=0) {
            if(num[left]<num[i]){
                beauty++;
            }
            left--;
        }
        ans[i] = beauty;
    }
    for(int i = 0; i < cnt; i++) {
        printf("%d ", ans[i]);
    }
    system("pause");
}