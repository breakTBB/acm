#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int n,m;
struct Stack{
	int a[100010];
	int top;
	void init(){top=0;}
	void push(int x){a[++top]=x;}
	void pop(){if(top)top--;}
	int size(){return top;}
	int query(){return a[top];}
};
struct Queue{
	int q[100010];
	int l,r;
	void init(){l=0;r=0;}
	void push(int x){
		if(r==100000)r=1;else r++;
		q[r]=x;
	}
	void pop(){if(l==100000)l=1;else l++;}
	int front(){return q[l];}
	int size(){if(l<=r)return r-l;else return l-r+1;}
	bool empty(){return l==r;}
};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)printf("%d%c",a[i],i==n-1?'\n':' ');
}
