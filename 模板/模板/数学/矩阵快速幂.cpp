#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long

using namespace std;

const int modd=1000000007;
const int maxn=110;
struct node{
	int x[maxn][maxn];
}a,b,tmp;

int n,k;

inline void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tmp.x[i][j]=0;
}

node mul(node x,node y){
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				tmp.x[i][j]=tmp.x[i][j]+x.x[i][k]*y.x[k][j];
				tmp.x[i][j]%=modd;
			}
		}
	}
	return tmp;
}

inline node poww(node x,int p)
{
	node ans;
	for(int i=1;i<=n;i++)
		ans.x[i][i]=1;
	while(p){
		if(p&1) ans=mul(ans,x);  
		x=mul(x,x);
		p/=2;
	}
	return ans;
}

main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&a.x[i][j]);
		}
	}
	node ans=poww(a,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.x[i][j]);
		putchar('\n');
	}
	return 0;
}
