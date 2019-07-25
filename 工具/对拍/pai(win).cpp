#include <cstdlib>
#include <cstdio>
#include <windows.h>

int main(void)
{
    int i;
    for(i=1;i<=1000;i++)
    {
        system("maker 100000000000000 >in");
        system("brute <in >bout");
        system("std <in >sout");

        if(system("fc bout sout"))
        {
            puts("GG");
            exit(0);
        }
        
        printf("Passed %d...\n",i);
        Sleep(1000);
    }
    return 0;
}
