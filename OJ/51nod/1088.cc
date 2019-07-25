#include <bits/stdc++.h>

using namespace std;

char s[1010];

int solve(int left, int right) {
    while(left<=right) {
        if (s[left]==s[right]) {
            left++;
            right--;
        } else {
            return 0;
        }
    }
    return 1;

}

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int ans = 1;
    // int start = 0;
    for (int i = 0; i < len; i++) {
        for (int start = 0; start <= i; start++) {
            if (solve(start, i)) {
                ans = max(ans, i - start + 1);
            }
        }
    }
    printf("%d", ans);
    system("pause");
}