#include <stdio.h>

void is(int a[],int count)
{
	for(int r = 1; r<count;++r){
		int l = r -1;
		int val = a[r];
		while(l>=0&&val<a[l])//val<a[l]不要错
		{ 
			a[l+1]=a[l];
		    l--;
		}
		//此时val >= a[l]   放在a[l]前面
		a[l+1]=val;//别写成a[l] - val
	}
	for(int i = 0;i < 5;i++){
		printf("%d   ",a[i]);
	}
}

int main()
{
	int a[5] = {445,3,9,2,70};
    is(a,5);
    return 0;
}
