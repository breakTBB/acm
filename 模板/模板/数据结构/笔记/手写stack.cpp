struct Stack{
	int a[100010];
	int top;
	void init(){top=0;}
	void push(int x){a[++top]=x;}
	void pop(){if(top)top--;}
	int size(){return top;}
	int query(){return a[top];}
};