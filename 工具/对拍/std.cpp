#include <bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int mod = 998244353;

int main()
{
//  freopen("in.txt","r",stdin);
    char s[100010]={'\0'};
    cin>>s;
    int a[100010]={0},ans=0;
    int ind=1;
    for(int i=0;s[i]!='\0';i++){
        a[ind]=s[i];
        while(ind>=3&&a[ind]==a[ind-1]&&a[ind-1]==a[ind-2]){
            ind-=3;
            ans++;
        }
        ind++;
    }
    cout<<ans;
    return 0;
}