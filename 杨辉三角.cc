#include <stdio.h>
int main() {
    int s = 1, n;
    int i, j;
    while(scanf("%d", &n)!=EOF) {
        printf("1\n");
        for (i = 2; i <= n; s = 1, i++) {
            printf("1 ");
            for (j = 1; j <= i - 2; j++)
                printf("%d ", (s = (i - j) * s / j));
            printf("1\n");
        }
        printf("\n");
    }
    return 0;
}