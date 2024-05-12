#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;


int main() {
	int M_num;
	int num;
	char loc;
	queue<int> deq;
	queue<int> enq;
	stack<int> ps;

	scanf_s("%d", &M_num);
	scanf_s(" %c", &loc);

	for (int i = 0; i < M_num; i++) {
		int num;
		scanf_s(" %d", &num);
		deq.push(num);
	}

	if (loc == 'a') {
		int s = 1;
		ps.push(deq.front());
			deq.pop();
		while (!deq.empty() && !ps.empty()) {
			if (!deq.empty() && deq.front() == s) {
				while (!deq.empty() && deq.front() == s) {
					enq.push(deq.front());
					deq.pop();
					s++;
				}
			}
			else if (!ps.empty() && ps.top() == s) {
				while ((!ps.empty() && ps.top() == s)) {
					enq.push(ps.top());
					ps.pop();
					s++;
				}
				if (!deq.empty()) {
					ps.push(deq.front());
					deq.pop();
				}
			}
			else {
				if (!deq.empty()) {
					ps.push(deq.front());
					deq.pop();
				}
			}
		}
		while (!ps.empty() && ps.top() == s) {
			enq.push(s);
			ps.pop();
			s++;
		}
	}
	else if (loc == 'd') {
		int s = M_num;
		ps.push(deq.front());
		deq.pop();
		while (!deq.empty() && !ps.empty()) {
			if (!deq.empty() && deq.front() == s) {
			while (!deq.empty() && deq.front() == s) {
					enq.push(deq.front());
					deq.pop();
					s--;
				}
			}
			else if (!ps.empty() && ps.top() == s) {
				while ((!ps.empty() && ps.top() == s)) {
					enq.push(ps.top());
					ps.pop();
					s--;
					}
				if (!deq.empty()) {
					ps.push(deq.front());
					deq.pop();
				}
			}
			else {
				if (!deq.empty()) {
					ps.push(deq.front());
					deq.pop();
				}
			}
		}
		while (!ps.empty() && ps.top() == s) {
			enq.push(s);
			ps.pop();
			s--;
		}
	}
	if (!ps.empty()) {
		printf("No");
	}
	else {
		printf("Yes");
	}
	//printf("\n");
	//while (!enq.empty()) {
	//	printf("%d ", enq.front());
	//	enq.pop();
	//}
	return 0;
}