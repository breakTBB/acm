#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1010][20];

int max(int a, int b) {
    return a > b ? a : b;
}

int cmp(const void * a, const void * b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int n;
    while(scanf("%d", &n), n != 0) {
        memset(str, 0, sizeof(str));
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        qsort(str, n, sizeof(char) * 20, cmp);
        char * ss;
        int count = 1;
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (strcmp(str[i], str[i - 1]) == 0) count++;
            else {
                if (count > m) {
                    m = count;
                    ss = str[i - 1];
                }
                count = 1;
            }
        }
        printf("%s", ss);
    }
    system("pause");
}