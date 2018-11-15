#include <bits/stdc++.h>

using namespace std;

char num[50010];

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    getchar();
    for(int i = 0; i < cnt; i++) scanf("%c%*c" ,&num[i]);
    int ans = 0;
    for(int i = 0; i < cnt - 1; i++) {
        for(int j = i + 1; j < cnt; j++) {
            if(num[i] > num[j]) ans++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}
