#include <bits/stdc++.h>
#define rep(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
const int mod = 998244353;
 
ll a[3010][3010];
int n,m;
char s[3010],t[3010];
ll ans=0;
ll dp[3010][3010];
int main() {
    int T;
    cin>>T;
    a[0][0]=1;
    rep(i,1,3005)rep(j,0,i)a[i][j]=(a[i-1][j-1]+a[i-1][j])%mod;
    while(T--){
        cin>>n>>m;
        cin>>s>>t;
        ans=0;
        rep(i,0,n-m-1)if(s[i]!='0')rep(j,m,n-i-1)ans=(ans+a[n-i-1][j])%mod;
        rep(i,0,n)rep(j,0,m)dp[i][j]=0;
        for(int j=m-1;j>=0;j--){
            for(int i=n-m+j;i>=0;i--){
                if(s[i]==t[j])
                    dp[i][j]=dp[i+1][j+1];
                else if(s[i]>t[j])
                    dp[i][j]=a[n-i-1][m-j-1];
                dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
            }
        }
        cout<<(ans+dp[0][0])%mod<<endl;
    }
    return 0;   
}