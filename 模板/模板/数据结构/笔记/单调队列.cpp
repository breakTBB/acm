/*

洛谷 P1886 滑动窗口 STL程序（各种优化都做的不大好，时间略长，但能AC）
“单调队列”数据结构 参考文档：
1、https://blog.csdn.net/a_bright_ch/article/details/77076228
2、https://blog.csdn.net/zhelong3205/article/details/77624699
3、https://blog.csdn.net/er111er/article/details/78344161
4、https://www.luogu.org/blog/hankeke/solution-p1886

建议真心想学的可以参考材料自己动手写一个。

Jack Ren from https://renjikai.com/
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<deque>
using namespace std;
int n, k;
int arr[1000005];
deque<int> dq,pq;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	//单调队列求最小
	for (int i = 1; i <= n; i++) {
		//维护队尾并插入
		while (!dq.empty() && dq.back() > arr[i]) { //求最大和最小的区别在第二个条件是大于号还是小于号
			dq.pop_back();
			pq.pop_back();
		}
		dq.push_back(arr[i]);
		pq.push_back(i);
		//剔除无效队首并获得最优解
		while (!pq.empty() && pq.back() - pq.front() >= k) {
			dq.pop_front();
			pq.pop_front();
		}
		if (i >= k)cout << dq.front() << " ";
	}
	cout << endl;
	dq.clear();
	pq.clear();
	//单调队列求最大
	for (int i = 1; i <= n; i++) {
		//维护队尾并插入
		while (!dq.empty() && dq.back() < arr[i]) { //求最大和最小的区别在第二个条件是大于号还是小于号
			dq.pop_back();
			pq.pop_back();
		}
		dq.push_back(arr[i]);
		pq.push_back(i);
		//剔除无效队首并获得最优解
		while (!pq.empty()&&pq.back() - pq.front() >= k) {
			dq.pop_front();
			pq.pop_front();
		}
		if (i >= k)cout << dq.front()<< " ";
	}
	
}
