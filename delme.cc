#include<cstdio>
#include<iostream>
using namespace std;
bool f[102000];
int n,a[110],sum;
int main()
{
    int i,j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]),sum+=a[i];
    }
    int tmp=sum/2;
    f[0]=true;
    for(i=1;i<=n;i++)
        for(j=tmp-a[i];j>=0;j--)
        if(f[j]) f[j+a[i]]=true;
    for(i=tmp;i;i--) if(f[i]) break;
    cout<<sum-2*i;  
    return 0;
}