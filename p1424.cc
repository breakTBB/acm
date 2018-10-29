#include <bits/stdc++.h>

using namespace std;

int main() {
    int dis = 0;
    int speed = 250;
    long long week = 0, day = 0;
    scanf("%d%d", &week, &day);
    while(day--){
        if(week>=1&&week<=5){
            dis += speed;
        }
        week++;
        if(8==week) {
            week = 1;
        }
    }
    printf("%d", dis);
}