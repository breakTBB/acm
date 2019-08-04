#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson (o<<1)
#define rson (o<<1|1)
#define dbg(x) cerr<<#x<<"="<<x<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void checkmax(int &x,int y){x=max(x,y);}
inline void checkmin(int &x,int y){x=min(x,y);}
inline int lowbit(int x){return x&(-x);}

const int N=1010;
struct Point{int x,y,z;}p[N];
int fa[N],mxh[N],cnt,n,m,h,r;
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int merge(int x,int y){
    int xx=find(x),yy=find(y);
    checkmax(mxh[yy],mxh[xx]);
    fa[xx]=yy;
}
inline ll sqr(int x){return 1LL*x*x;}
inline int check(int i,int j){
    if(i==0||j==0){
        int mx=max(i,j);
        if(p[mx].z<=r)return 1;else return 0;
    }
    ull dis=1uLL*sqr(p[i].x-p[j].x)+1uLL*sqr(p[i].y-p[j].y)+1uLL*sqr(p[i].z-p[j].z);
    return dis<=sqr(2LL*r);
}
inline void init(){
    n=read();h=read();r=read();
    for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read(),p[i].z=read();
    for(int i=1;i<=n;i++)fa[i]=i,mxh[i]=p[i].z+r;
    fa[0]=0;mxh[0]=0;
    p[0].x=0;p[0].y=0;p[0].z=0;
}
inline void solve(){
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
        if(find(i)==find(j))continue;
        if(check(i,j))merge(i,j);
    }
    if(mxh[find(0)]>=h)puts("Yes");else puts("No");
}
int main(){
    //freopen("cheese.in","r",stdin);
    //freopen("cheese.out","w",stdout);
    for(int T=read();T;T--){
        init();
        solve();
    }
}