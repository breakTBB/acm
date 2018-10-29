#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[1010];
    int cnt;
    fill(str,str+1010,'0');
    scanf("%d", &cnt);
    scanf("%s",str);
    int f = 1;
    //special case
    if(cnt==1&&str[0]=='0'){
        f = 0;
    }
    else if(str[0]=='0'&&str[1]=='0'){
        f = 0;
    }else if(str[cnt-2]=='0'&&str[cnt-1]=='0'){
        f = 0;
    }
    //two rule
    for(int i = 0; i < cnt; i++){
        //不能相邻
        if(str[i]=='1'){
            if(str[i+1]=='1'){
                f = 0;
                break;
            }
        }else if(str[i]=='0'&&str[i+1]=='0'&&str[i+2]=='0'){
        f = 0;
        }
    }
    if(f)puts("Yes");
    else puts("No");
}