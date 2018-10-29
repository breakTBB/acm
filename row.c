#include <stdio.h>

int main()
{
    char str[1010];
    int cnt;
    scanf("%d", &cnt);
    scanf("%s",str);
    str[cnt] = '0';
    int f = 1;
    //单独0
    if(cnt==1&&str[0]=='0'){
        f = 0;
    }

    //前后00     
    if(str[0]=='0'&&str[1]=='0'){
        f = 0;
    }
    if(str[cnt-2]=='0'&&str[cnt-1]=='0'){
        f = 0;
    }

    for(int i = 0; i < cnt; i++){
        //连续1
        if(str[i]=='1'){
            if(str[i+1]=='1'){
                f = 0;
                break;
            }
        }
        if(str[i]=='0'&&str[i+1]=='0'&&str[i+2]=='0'){
            f = 0;
            break;
        }
    }
    if(f)puts("Yes");
    else puts("No");
}