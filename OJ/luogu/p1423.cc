#include <bits/stdc++.h>

using namespace std;

int main() {
    double dis = 0;
    double speed = 2;
    int step = 0;
    scanf("%lf", &dis);
    while(dis>0) {
        dis -= speed;
        speed *= 0.98;
        step++;
    }
    printf("%d", step);
    
}