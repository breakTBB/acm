// G. 2017

// Given a, b, c, d, find out the number of pairs of integers (x, y) where a ≤ x ≤ b, c ≤ y ≤ d and x · y is multiple of 2017.

// Input

// The input contains zero or more test cases and is terminated by end-of-file.
// Each test case contains four integers a, b, c, d.
// • 1 ≤ a ≤ b ≤ 109 , 1 ≤ c ≤ d ≤ 109
// • The number of tests cases does not exceed 104

// Output

// For each case, output an integer which denotes the result.

// Sample Input

// 1 2017 1 2016
// 1 1000000000 1 1000000000

// Sample Output

// 2016
// 991324197233775


#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d;
    while(cin>>a>>b>>c>>d){
        long long len1 = b-a+1;
        long long len2 = d-c+1;
        long long m= 0 ,n=0;
        m = b/2017 - a/2017;    //[a, b]中2017的个数
        if(a%2017 == 0){
            m++;    //特判a为2017倍数
        }
        n = d/2017 - c/2017;    //[d, c]中2017的个数
        if(c%2017 == 0){
            n++;
        }
        unsigned long long res = 0;
        //逆向思维，选取x, y用乘法原理
        res = len1*len2 - (len1-m)*(len2-n);
        cout<<res<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define maxs 202020
// #define mme(i,j) memset(i,j,sizeof(i))
// using namespace std;

// long long cel(int l,int r,int p)
// {
//     long long ans =0;
//     ans = (r/p)- ( (l-1)/p );
//     return ans;
// }

// int main()
// {
//     long long int a,b,c,d;
//     while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){

//         printf("%lld\n",cel(a,b,2017)*(d-c+1)+cel(c,d,2017)*(b-a+1) - cel(a,b,2017)*cel(c,d,2017) );
//     }
//     return 0;
// }