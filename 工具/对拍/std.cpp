#include <cstdio>
using namespace std;
typedef long long LL;
const int N=10000010;
LL n,ansl[N],ansr[N];
int main(){
    while(~scanf("%lld",&n)){
        LL l=1,r=0,s=0;int cnt=0;
        for(;l*l<=n;s-=l*l,l++){
            while((r+1)*(r+1)<=n&s<n){r++;s+=r*r;}
            if(s==n){ansl[++cnt]=l;ansr[cnt]=r+1;}
        }printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++){
            printf("%lld",ansr[i]-ansl[i]);
            for(int j=ansl[i];j<ansr[i];j++)printf(" %d",j);
            puts("");
        }
    }return 0;
}
