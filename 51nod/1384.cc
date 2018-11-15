#include <bits/stdc++.h>

using namespace std;

char str[10];

int main(int argc, char const *argv[])
{
    int s_s;
    scanf("%s", str);
    int len = strlen(str);
    sort(str, str+len);
    printf("%s\n", str);
    while(next_permutation(str, str+len)) {
        printf("%s\n", str);
    }
    system("pause");
    return 0;
}
