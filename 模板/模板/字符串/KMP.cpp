/*洛谷 模板 KMP*/
/*经典的两个字符串匹配算法*/
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn=1000010;
char s1[maxn],s2[maxn];
int kmp[maxn];

int main() {
    scanf("%s",s1);
    scanf("%s",s2);
    int n1=strlen(s1);
    int n2=strlen(s2);
    int k=0;
    for(int i=1;i<n2;i++)
    {
        while(k && s2[i]!=s2[k])
            k=kmp[k];
        if(s2[i]==s2[k])kmp[i+1]=++k;
    }
    k=0;
    for(int i=0; i<n1; i++) {
        while(k && s1[i]!=s2[k])
            k=kmp[k];
        if(s1[i]==s2[k])
            k+=1;
        if(k==n2)
            printf("%d\n",i-n2+2);
    }
    for(int i=1; i<=n2; i++)printf("%d ",kmp[i]);
    return 0;
}

