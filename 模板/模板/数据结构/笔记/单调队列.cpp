/*

��� P1886 �������� STL���򣨸����Ż������Ĳ���ã�ʱ���Գ�������AC��
���������С����ݽṹ �ο��ĵ���
1��https://blog.csdn.net/a_bright_ch/article/details/77076228
2��https://blog.csdn.net/zhelong3205/article/details/77624699
3��https://blog.csdn.net/er111er/article/details/78344161
4��https://www.luogu.org/blog/hankeke/solution-p1886

����������ѧ�Ŀ��Բο������Լ�����дһ����

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
	//������������С
	for (int i = 1; i <= n; i++) {
		//ά����β������
		while (!dq.empty() && dq.back() > arr[i]) { //��������С�������ڵڶ��������Ǵ��ںŻ���С�ں�
			dq.pop_back();
			pq.pop_back();
		}
		dq.push_back(arr[i]);
		pq.push_back(i);
		//�޳���Ч���ײ�������Ž�
		while (!pq.empty() && pq.back() - pq.front() >= k) {
			dq.pop_front();
			pq.pop_front();
		}
		if (i >= k)cout << dq.front() << " ";
	}
	cout << endl;
	dq.clear();
	pq.clear();
	//�������������
	for (int i = 1; i <= n; i++) {
		//ά����β������
		while (!dq.empty() && dq.back() < arr[i]) { //��������С�������ڵڶ��������Ǵ��ںŻ���С�ں�
			dq.pop_back();
			pq.pop_back();
		}
		dq.push_back(arr[i]);
		pq.push_back(i);
		//�޳���Ч���ײ�������Ž�
		while (!pq.empty()&&pq.back() - pq.front() >= k) {
			dq.pop_front();
			pq.pop_front();
		}
		if (i >= k)cout << dq.front()<< " ";
	}
	
}
