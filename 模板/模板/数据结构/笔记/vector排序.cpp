#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)printf("%d%c",a[i],i==n-1?'\n':' ');
}