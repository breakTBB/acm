#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int main(){
	cin>>t;
	int cas=0;
	while(t--){
		cin>>n>>m;
		cout<<"Case "<<(++cas)<<": ";
		if(m==1){
			if(n&1) cout<<"first";
			else cout<<"second";
		}
		else{
			if(n<=m){
				cout<<"first";
			}
			else
			cout<<"second";
		}
		cout<<"\n";
	}
	return 0;
}