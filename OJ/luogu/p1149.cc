#include <bits/stdc++.h>

using namespace std;

int sum;
int ans;
int match[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(int argc, char const *argv[])
{
    cin >> sum;
    // 循环中要操作循环变量时
    //一定要重新定义一个变量
    for(int x = 0; x <= 1000; x++) {
        for(int y = 0; y <= 1000; y++) {
            int i = x;
            int j = y;
            int k = i + j;
            int mi = 0, mj = 0, mk = 0;

            if(i >= 10) {
                while(i > 0) {
                    mi += match[i%10];
                    i /= 10;
                }
            } else {
                mi = match[i];
            }

            if(j >= 10) {
                while(j > 0) {
                    mj += match[j%10];
                    j /= 10;
                }
            } else {
                mj = match[j];
            }

            if(k >= 10) {
                while(k > 0) {
                    mk += match[k%10];
                    k /= 10;
                }
            } else {
                mk = match[k];
            }

            if(mi + mj + 4 + mk == sum) ans++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}
