#include <bits/stdc++.h>

using namespace std;
const int maxn = 110;
char str[maxn];
int main(){
    freopen("input.txt","r",stdin);
    int cnt;
    scanf("%d", &cnt);
    getchar();
    for(int c = 0; c < cnt; c++) {
        memset(str,sizeof(str),0);
        char tmp;
        int index = 0;
        scanf("%c", &tmp);
        while(tmp!='\n') {
            str[index++] = tmp;
            if(scanf("%c", &tmp)==EOF)goto fuck;
        }
        fuck:
        str[index] = '\0';
        int a = 0, e = 0, iiii = 0, o = 0, u = 0;
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            if(str[i]=='a')a++;
            if(str[i]=='e')e++;
            if(str[i]=='i')iiii++;
            if(str[i]=='o')o++;
            if(str[i]=='u')u++;
        }
        // printf("%d %d %d %d %d ", a, e, iiii, o, u);
        printf("a:%d\n",a);
        printf("e:%d\n",e);
        printf("i:%d\n",iiii);
        printf("o:%d\n",o);
        printf("u:%d\n\n",u);
    }
    system("pause");
}