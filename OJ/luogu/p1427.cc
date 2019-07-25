// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// ll num[110];

// int main() {
//     int index = 0;
//     scanf("%d", &num[index]);
//     while(num[index]!=0) {
//         index++;
//         scanf("%d", &num[index]);
//     }
//     for(int i = index-1; i >= 0; i--) {
//         printf("%d ", num[i]);
//     }
//     system("pause");
// }

#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s;
    while(true) {
        int a;
        scanf("%d", &a);
        if(!a)break;
        s.push(a);
    }
    while(!s.empty()) {
        cout << s.top();
        putchar(32);
        s.pop();
    }
}