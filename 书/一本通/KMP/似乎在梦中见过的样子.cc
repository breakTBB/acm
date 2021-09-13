#include<cstring>
#include<cstdio>
using namespace std;
const int M=2e4+111;
int n,k,res;
int nxt[M]; char s[M];
int main(){
    scanf("%s%d",s+1,&k),n=strlen(s+1);
    for(int t=1,i,j;t<=n-(k<<1);++t){
        for(i=1;i<=t;++i) nxt[i]=t-1;   //这里不加等着 T 飞吧
        for(i=t+1,j=t-1;i<=n;++i){   
            while(j^t-1 && s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1]) ++j; nxt[i]=j;
        }   //nxt 数组是要先预处理的，然后才能处理答案
        for(i=t+1,j=t-1;i<=n;++i){
            while(j^t-1 && s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1]) ++j;
            while(j-t+1>=i-j) j=nxt[j];    //题目中的 B 没了，跳向 nxt 
            if(j-t+1>=k) ++res;  //长度满足就累加答案
        }
    } printf("%d\n",res); return 0;
}