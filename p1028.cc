#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int f[1010];

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(i % 2 == 0) {
            f[i] = f[i -1] + f[i / 2];
        } else {
            f[i] = f[i -1];
        }
    }
    cout << f[n];
    system("pause");
}
