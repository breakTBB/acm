/*
	Author : FlierKing
	Language : C++
	Problem : LG1807
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#define INF 2147483647
#define ll long long
#define random(x) rand()%x
#define PI 3.1415926
#define fi first
#define se second
using namespace std;
struct sth
{
    int num;
    vector<pair<int,int> > b;
}p[2010];
    int n,m,f,t,w,st,en;
    pair<int,int> tmp;
    int v[2010],l[100000],ind[2010];
void solve()
{
	v[1]=0,st=1,en=0;
	for (int i=1;i<=n;i++)
		if (ind[i]==0) l[++en]=i;
	while (st<=en)
	{
		int x=l[st++];
	    for (int i=0;i<p[x].num;i++)
	    {
	        if (v[x]!=-1&&v[x]+p[x].b[i].se>v[p[x].b[i].fi])
	            v[p[x].b[i].fi]=v[x]+p[x].b[i].se;
	        ind[p[x].b[i].fi]--;
	        if (ind[p[x].b[i].fi]==0)
	        	l[++en]=p[x].b[i].fi;
		}
	}
}
int main()
{
    memset(v,-1,sizeof(v));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&f,&tmp.fi,&tmp.se);
        p[f].num++;
        p[f].b.push_back(tmp);
        ind[tmp.fi]++;
    }
    solve();
    printf("%d",v[n]);
    return 0;
}
