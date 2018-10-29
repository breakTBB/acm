#include <bits/stdc++.h>

using namespace std;

char str[1000010];

int main(){
    // ios::sync_with_stdio(false);
    // char * str = "abcdabcd";
    // bool flag = false;
    // for(int i = 0; i < 8; i++){
    //     for(int j = i; j < i+8; j++){
    //         printf("%c", str[j%8]);
    //     }
    //     puts("");
    // }
    // system("pause");

// abcdabcd
// bcdabcda
// cdabcdab
// dabcdabc
// abcdabcd
// bcdabcda
// cdabcdab
// dabcdabc

    while(~scanf("%s", str)){
        int flag = 0;
        int len = strlen(str);
        if(len % 2 != 0){
            puts("NO");
            continue;
        }
        for(int i = 0; i < len/2; i++){
            if(str[i]!=str[i+len/2]){
                puts("NO");
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("YES");
        }
    }
    return 0;
}