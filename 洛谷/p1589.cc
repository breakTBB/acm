#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main() {
    char tmp;
    while(~scanf("%c", &tmp)) {
        if(tmp>='A' && tmp<='Z') {
            cnt[tmp-'A']++;
        }
    }
    int maxcnt = *max_element(cnt,cnt+30);
    for(int i  = maxcnt; i > 0; i--) {
        for(int j = 'A'; j <= 'Z'; j++) {
            if(cnt[j-'A']>=i)printf("*");
            else printf(" ");
            if(j!='Z')printf(" ");
        }
        printf("\n");
    }
    for(int i = 'A'; i <= 'Z'; i++){
        putchar(i);
        if(i!='Z')printf(" ");
    }
    system("pause");
}