#include<bits/stdc++.h>
const int N=10000+10;
using namespace std;
int fa[N],n,m;
int find(int x){if(x==fa[x])return x;else return fa[x]=find(fa[x]);}
int merge(int x,int y){
    int xx=find(x),yy=find(y);
    fa[yy]=xx;
}
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--){
        int opt=read(),x=read(),y=read();
        if(opt==1)merge(x,y);
        else{
            int xx=find(x),yy=find(y);
            if(xx==yy)puts("Y");else puts("N");
        }
    }
}
