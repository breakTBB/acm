#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int a, b, sum = 0;
    scanf("%d%d", &a, &b);
    for(int i = 1; i < 1000; i++){
        sum += i;
        if(a-sum==b-(sum+i+1)) {
            printf("%d",sum-a);
            break;
        }
    }
    system("pause");
}