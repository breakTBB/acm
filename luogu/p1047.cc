#include <bits/stdc++.h>

using namespace std;

int lastl = 0, lastr = 0;
int start = 0, endd = 0;
bool tree[10020];
int main() {
    int length = 0;
    int cnt = 0;
    int sum = 0;
    scanf("%d%d", &length, &cnt);
    for(int i = 0; i < cnt; i++) {
        int left, right;
        scanf("%d%d", &left, &right);
        for(;left <= right;left++)tree[left]=true;
    }
    for(int i = 0; i <= length; i++) {
        if(tree[i]==false)sum++;
    }
    printf("%d", sum);
    system("pause");
}