#include <stdio.h>

typedef long long LL;

LL C(int m,int n) {
    int k=1;//相当于C(m,n)
    LL ans=1;
    while(k<=n) {
        ans=((m-k+1)*ans)/k;
        k++;
    }
    return ans;
}
LL P(int m, int n) {
    int product = 1;
    while(n--) {
        product *= m;
        m--;
    }
    return product;
}

int main() {
    printf("%d", C(25, 13));
    puts("");
    printf("%d", P(3,2));
    getchar();
}