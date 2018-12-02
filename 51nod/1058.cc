#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
//斯特林公式n!=sqrt(2*PI*n)*(n/e)^n
#define PI 3.1415926

using namespace std;

int main()
{
    int n, a;
    while(~scanf("%d",&n))
    {
        a = (int)((0.5 * log(2 * PI * n) + n * log(n) - n) / log(10));
        printf("%d\n", a + 1);
    }
    return 0;
}

int main2()
{
	int i,j,n;
	double sum;
	sum=1;
	cin>>n;
	for(i=1;i<=n;i++) {
		sum+=log10(double(i));
	}
	cout<<(int)sum<<endl;
	return 0;
}
