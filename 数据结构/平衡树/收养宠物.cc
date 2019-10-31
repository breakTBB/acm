#include<bits/stdc++.h>
using namespace std;
const int mod=1000000,INF=0x7fffffff;
set<int>a[2];
set<int>::iterator it;
int n,ans=0;
int main() {
    int opt,x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&opt,&x);
        if(a[opt^1].empty()){a[opt].insert(x);continue;}

        if(x>*(--a[opt^1].end())) {
            ans+=x-*(--a[opt^1].end());ans%=mod;
            a[opt^1].erase(*(--a[opt^1].end()));
        }
        else if(x<*(a[opt^1].begin())) {
            ans+=*(a[opt^1].begin())-x;ans%=mod;
            a[opt^1].erase(*(a[opt^1].begin()));
        }
        else {
            it=a[opt^1].lower_bound(x);
            int nxt=*it,pre=*(--it);
            if(x-pre<=nxt-x)a[opt^1].erase(pre),ans=(ans+x-pre)%mod;
            else a[opt^1].erase(nxt),ans=(ans+nxt-x)%mod;
        }
    }
    cout<<ans;
    return 0;
}