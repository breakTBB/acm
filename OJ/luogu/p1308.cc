#include <bits/stdc++.h>

using namespace std;

char str[110][20];
char word[20];
bool flag = true;
bool first = true;
int fff;

int main() {
    freopen("input.txt","r",stdin);
    int num = 0;
    int count = 0;
    scanf("%s", word);
    while(~scanf("%s", str[num]))num++;
    int len = strlen(word);
    for(int i = 0; i <= num; i++) {
        int length = strlen(str[i]);
        if(len==length) {
            for(int j = 0; j < length; j++) {
                str[i][j] = str[i][j] > 'Z' ? str[i][j] - 32:str[i][j];
                word[j] = word[j] > 'Z' ? word[j] - 32 : word[j];
                if(str[i][j] != word[j])flag = false;
            }
            if(flag)count++;
            if(first&&flag){
                fff = i;
                first = false;
            }

        } else {
            flag = false;
        }
    }
    if(!count)printf("-1");//flag
    else {
        printf("%d %d", count, fff);
    }
    freopen("CON", "r", stdin);
    system("pause");
}