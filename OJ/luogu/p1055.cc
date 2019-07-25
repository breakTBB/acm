#include <bits/stdc++.h>

using namespace std;

char str[14];

int main() {
    scanf("%s", str);
    int num = 0;
    num += (str[0]-'0') * 1;
    num += (str[2]-'0') * 2;
    num += (str[3]-'0') * 3;
    num += (str[4]-'0') * 4;
    num += (str[6]-'0') * 5;
    num += (str[7]-'0') * 6;
    num += (str[8]-'0') * 7;
    num += (str[9]-'0') * 8;
    num += (str[10]-'0') * 9;
    num %= 11;
    if(str[12]=='X'&&num==11)
        printf("Right");
    else{
        if(str[12]-'0'==num)printf("Right");
        else{
            for(int i = 0; i < 12; i++) {
                printf("%c",str[i]);
            }
            if(num==11)
            printf("X");
            else printf("%d",num);
        }
    }
}