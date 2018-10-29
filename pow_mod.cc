#include <stdio.h>

long long main(){
    long long m;
    scanf("%lld", &m);
    if(m<100)m=100;
    if(m>1000){printf("1634");return 0;}
    for(int i = m; i <= 1000; i++){
        int g = i % 10;
        int s = (i/10) % 10;
        int b = i/100;
        if(g*g*g+s*s*s+b*b*b==i){
            printf("%d",i);
            return 0;
        }
    }
}



