#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=408;
struct poi{
    int x,y,v;
}f[maxn];
int lena[maxn],lenb[maxn];
int a[maxn],b[maxn];
int idx,idy;
int mp[maxn][maxn];

map<int,int> X,Y;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        idx=0;idy=0;
        a[idx++]=0;b[idy++]=0;
        a[idx++]=1000000010;b[idy++]=1000000010;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&f[i].x,&f[i].y,&f[i].v);
            a[idx++]=f[i].x;b[idy++]=f[i].y;
        }
        sort(a,a+idx);sort(b,b+idy);
        int sn=unique(a,a+idx)-a;
        int sm=unique(b,b+idy)-b;
        X.clear();Y.clear();
        int dn=0,dm=0;
        for(int i=1;i<sn;i++)
        {
            if(a[i]>a[i-1]+1)
            {
                lena[++dn]=a[i]-a[i-1]-1;
            }
            lena[++dn]=1;
            X[a[i]]=dn;
        }
        for(int i=1;i<sm;i++)
        {
            if(b[i]>b[i-1]+1)
                lenb[++dm]=b[i]-b[i-1]-1;
            lenb[++dm]=1;
            Y[b[i]]=dm;
        }
        memset(mp,-1,sizeof(mp));
        for(int i=1;i<=dn;i++)
            for(int j=1;j<=dm;j++)
                mp[i][j]=0;
        for(int i=0;i<n;i++)
        {
            int x=f[i].x,y=f[i].y;
            mp[X[x]][Y[y]]=f[i].v;
        }
        /*for(int i=1;i<=dn;i++)
        {
            for(int j=1;j<=dm;j++)
                printf("%d ",mp[i][j]);
            printf("\n");
        }*/

        for (int i = 1; i <= dn; i++) {
            for (int j = 1; j <= dm; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i - 1][j - 1] + mp[i][j], dp[i][j]);
            }
        }
        cout << dp[dn][dm] << endl;
    }
    return 0;
}