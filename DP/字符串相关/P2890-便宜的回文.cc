#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
char ch1[233] = "#helloworld";
char ch2[233] = "#HELLOWORLD";
int f[233];

int main() {
    char x; f[0] = 1;
    while ((x = getchar())!=EOF) 
        for (int i = 10; i >= 1; -- i) 
            if (x == ch1[i] || x == ch2[i]) 
                f[i] = (f[i-1] + f[i]) % MOD;
    cout << f[10] << endl;
    return 0;
}