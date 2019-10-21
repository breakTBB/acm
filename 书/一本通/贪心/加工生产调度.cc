#include<bits/stdc++.h>
using namespace std;
int n,ans[10000],ti[10000],a[10000],b[10000];
struct node{
    int mi,wan;//mi:A和B中时间更短的,wan:序号 
}hzy[10000];
inline int v(node x,node y){
    return x.mi<y.mi;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        hzy[i].wan=i;
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>b[i];
        hzy[i].mi=min(a[i],b[i]);
    }
    sort(hzy+1,hzy+1+n,v);
    int z=0,y=n+1;
    for(int i=1;i<=n;i++){
        if(hzy[i].mi==a[hzy[i].wan]){//A时间短的往前面塞 
            z++;
            ans[z]=hzy[i].wan;
        }
        else{//反之，B时间短的往后面塞 
            y--;
            ans[y]=hzy[i].wan;
        }
    }
    for(int i=1;i<=n;i++){
        ti[i]=ti[i-1]+a[ans[i]];
    }//轮到某一个零件时A车间的总加工时间 
    int sum=ti[1]+b[ans[1]];
    for(int i=2;i<=n;i++){
        sum=max(ti[i],sum)+b[ans[i]];
    }//要等到A车间加工完:t[i],或等到B车间加工完:sum。再取其中最大值。 
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}