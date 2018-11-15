#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int q, x;
    char com[20];
    list<int> v;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%s", com);
        if('i' == com[0]) {
            scanf("%s", com);
            v.push_front(x);
        } else if ('L' == com[6]) {
            v.pop_back();
        } else if ('F' == com[6]) {
            v.pop_front();
        } else if ('d' == com[0]) {
            scanf("%d", &x);
            for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == x) {
                    v.erase(it);
                    break;
                }
            }
        }
    }
    int i = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (i++) printf(" ");
        printf("%d", *it);
    }
    printf("\n");
    return 0;
}
