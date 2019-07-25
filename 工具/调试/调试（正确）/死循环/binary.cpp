#include <cstdio>
#include <cstdlib>

int f(int x)  {return 2*x*x-3*x-10;}

int main(void)
{
    int l=1,r=10,mid;

    while(l < r)
    {
        if(r-l<=5) goto finish;
        printf("[%d,%d]\n",l,r);
        mid = (l+r)/2;

        if(f(mid) >= 0) r=mid;
        else l=mid+1;
    }
    finish:
    //把[l,r]里面的数逐一检查

    printf("%d\n",l);
    
    return 0;
}
