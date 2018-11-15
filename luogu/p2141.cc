#include <bits/stdc++.h>

int num[10010];
int vis[100100];
int visans[100100];

int main() {
    int cnt;
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }
    int ans = 0;
    for(int i = 0; i < cnt; i++) {
        for(int left = 0; left < cnt; left++) {
            for(int right = 0; right < cnt; right++) {
                if((num[i]==num[left]+num[right])&&num[i]!=num[left]&&num[i]!=num[right]&&num[left]!=num[right])
                    if(!visans[num[i]]){
                        visans[num[i]] = 1;
                        ans++;
                    }
                    // if(!vis[num[left]]||!vis[num[right]]) {
                    //     ans++;
                    //     vis[num[left]] = 1;
                    //     vis[num[right]] = 1;
                    //     visans[num[i]] = 1;
                    // }
            }
        }
    }
    std::cout << ans;
    system("pause");
}