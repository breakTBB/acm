/*
	Author : ThatXX
	Language : C++
	Problem : LG1629
	BlogUrl : https://www.luogu.org/blog/vip/p1629-you-di-yun-song-xin
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define M 100001
#define maxn 999999
using namespace std;
queue<int> q;
int n,m,tot,tat;
int u,v,w[M];
int dis1[M],dis2[M],vis[M];
int to1[M],net1[M],head1[M];
int to2[M],net2[M],head2[M];
void add1(int u,int v,int z) {
    to1[++tot]=v; net1[tot]=head1[u]; head1[u]=tot; w[tot]=z;
}
void add2(int u,int v,int z) {
    to2[++tat]=v; net2[tat]=head2[u]; head2[u]=tat; w[tat]=z;
}
void spfa1(int x) {
    for(int i=1; i<=n; i++) {
        dis1[i]=maxn;
        vis[i]=0;
    }
    dis1[x]=0,vis[x]=1,q.push(x);
    while(!q.empty()) {
        int y=q.front(); q.pop(); vis[y]=0;
        for(int i=head1[y]; i; i=net1[i]) {
            int t=to1[i];
            if(dis1[t]>dis1[y]+w[i]) {
                dis1[t]=dis1[y]+w[i];
                if(!vis[t]) vis[t]=1,q.push(t);
            }
        }
    }
}
void spfa2(int x) {
    for(int i=1; i<=n; i++) {
        dis2[i]=maxn;
        vis[i]=0;
    }
    dis2[x]=0,vis[x]=1,q.push(x);
    while(!q.empty()) {
        int y=q.front(); q.pop(); vis[y]=0;
        for(int i=head2[y]; i; i=net2[i]) {
            int t=to2[i];
            if(dis2[t]>dis2[y]+w[i]) {
                dis2[t]=dis2[y]+w[i];
                if(!vis[t]) vis[t]=1,q.push(t);
            }
        }
    }
}
int main() {
    int a=0,b=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d",&u,&v,&w[i]);
        add1(u,v,w[i]);
        add2(v,u,w[i]);
    }
    spfa1(1);
    memset(vis,0,sizeof(vis));
    spfa2(1);
    for(int i=1; i<=n; i++) {
        a+=dis1[i];
        b+=dis2[i];
    }
    printf("%d",a+b);
    return 0;
}
