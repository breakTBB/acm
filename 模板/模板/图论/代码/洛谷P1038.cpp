/*
	Author : faker121
	Language : C++
	Problem : LG1038
	BlogUrl : https://www.luogu.org/blog/user48628/solution-p1038
*/ 

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,p;
struct fuck
{
    int y;
    int val;
    int next;
}a[30010];
int c[110],u[110],in[110],out[110],cnt,head[30010];
bool v[110];
queue <int> q;
struct gay
{
    int x;
    friend bool operator < (gay a,gay b)
    {
        return a.x>b.x;
    }
}g;
priority_queue <gay> print;
void add(int x,int y,int val)
{
    cnt++;
    a[cnt].y=y;
    a[cnt].val=val;
    a[cnt].next=head[x];
    head[x]=cnt;
}
int main()
{
    scanf("%d%d",&n,&p);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&u[i]);
        if (c[i]!=0) q.push(i),v[i]=1;
        else c[i]-=u[i];
    }
    for (int i=1;i<=p;i++)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        add(x,y,val);
        in[y]++;
        out[x]++;
    }
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        v[x]=0;
        if (c[x]<0) continue;
        for (int i=head[x];i;i=a[i].next)
        {
            int y=a[i].y;
            if (v[y]==0)
            {
                c[y]+=a[i].val*c[x];
                q.push(y),v[y]=1;
            }
            else
            {
                c[y]+=a[i].val*c[x];
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (out[i]==0&&c[i]>0)
        {
            gay gg;
            gg.x=i;
            print.push(gg);
        }
    }
    if (print.empty())
    {
        printf("NULL");
        return 0;
    }
    while (!print.empty())
    {
        gay t=print.top();
        print.pop();
        printf("%d %d\n",t.x,c[t.x]);
    }
    return 0;
}
