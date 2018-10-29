/*
1.交换相邻两数的最小次数为该序列的逆序数
2.交换任意两数 元素个数-循环节个数
3.交换任意区间 TODO
*/
#include <bits/stdc++.h>

using namespace std;

int getMinSwaps(vector<int> &A) {
    auto len = A.size();
    vector<int> B(A);
    sort(B.begin(), B.end());
    map<int, int> m;
    for(auto i = 0; i < len; i++) {
        m[B[i]] = i;
    }
    int loops = 0;
    vector<bool> flag(len, false);
    for(auto i = 0; i < len; i++) {
        if(!flag[i]) {
            int j = i;
            while(!flag[j]) {
                flag[j] = true;
                //原序列中j位置的元素
                //在有序序列中的位置
                j = m[A[j]];
            }
            loops++;
        }
    }
    return len - loops;
}

int main() {
    vector<int> num;
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
    num.push_back(6);
    int ans = getMinSwaps(num);
    cout << ans;
    getchar();
}