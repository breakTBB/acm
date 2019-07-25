#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc,char** argv)
{
    int n=atoi(argv[1]);
    srand(time(0));

    printf("%d\n",(rand() * 1ll * 1000000000) % n);

    return 0;
}
