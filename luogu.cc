#include <bits/stdc++.h>

using namespace std;
int b[10]={0};
int main(){
    for(int start = 123; start <= 987; start++) {
        int bf = start * 2;
        int c = start * 3;
        if (c > 999)break;

        b[1] = start / 100;
        b[2] = (start / 10) % 10;
        b[3] = start % 10;

        b[4] = bf / 100;
        b[5] = (bf / 10) % 10;
        b[6] = bf % 10;

        b[7] = c / 100;
        b[8] = (c / 10) % 10;
        b[9] = c % 10;
        bool f = true;
        for(int i = 1; i <= 9; i++) {
        for(int j = i+1; j<=9;j++){
            if (b[i]==b[j]||b[i]==0) {
                f = false;
            }
        }
    }
        if(f)printf("%d %d %d\n",start,bf,c);
    }
    system("pause");

}