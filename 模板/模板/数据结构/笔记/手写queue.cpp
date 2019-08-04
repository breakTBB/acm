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