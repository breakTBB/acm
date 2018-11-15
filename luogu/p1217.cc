#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if(n <= 1||2 == n) return false;
    int s = sqrt(n) + 1;
    for(int i = 2; i <= s; i++) 
        if(n % i == 0) return false;
    return true;
}

int palindrome(int n) {
    int res = n;
    n /= 10;
    while(n) {
        int tmp = n % 10;
        res = res * 10 + tmp;
        n /= 10;
    }


    return res;
}

int main(int argc, char const *argv[])
{
    int a, b;
    // cin >> a >> b;
    a = 7;b = 10000000;
    // cout << palindrome(1234);
    if(a == 5) cout << 5 << "\n";
    if(a <= 6) cout << 7 << "\n";
    if(a <= 11) cout << 11 << "\n";
    for(int i = 10; i <= 10000; i++) {
        int num = palindrome(i);
        if(isPrime(num) && num >= a && num <= b) cout << num << "\n";
    }
    return 0;
}
