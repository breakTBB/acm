#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

int q[MAXN],head=-1,tail=-1;
int s[MAXN],tops=-1;

void push_queue(int x) {
	q[++head] = x;
}

int pop_queue() {
	return q[++tail];
}

bool is_empty() { 
	return head == tail;
}


void push_stack(int x) {
	s[++tops] = x;
}

int pop_stack() {
	return s[tops--];
}

int main() {

    push_stack(1);
	push_stack(2);
	cout<<pop_stack()<<endl;
	cout<<pop_stack()<<endl;
}