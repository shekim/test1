#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define MAX_QUEUE_SIZE 100

inline void error(const char* message){
	printf("%s\n", message);
	exit(1);
}
class CircularQueue{
protected:
	int front;
	int rear;
	string data[MAX_QUEUE_SIZE];
public:
	CircularQueue(){
		front = rear = 0;
	}
	bool isEmpty(){
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	void enqueue(string val){
		if (isFull()) {
			error("error:큐가 포화상태입니다\n");
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	string dequeue() {
		if (isEmpty()) {
			error(" error: 큐가 공백상태입니다\n");
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	string peek(){
		if (isEmpty()) {
			error(" Error: 큐가 공백상태입니다\n");
		}
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
};

class CircularDeque :public CircularQueue {
public:
	CircularDeque() {
	}
	void addRear(string val) {
		enqueue(val);
	}
	string deleteFront() {
		return dequeue();
	}
	string getFront() {
		return peek();
	}
	string getRear() {
		if (isEmpty()) {
			error("포화");
		}
		else {
			return data[rear];
		}
	}
	void addFront(string val) {
		if (isFull()) {
			error("포화");
		}
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	string deleteFear() {
		if (isEmpty()) {
			error("공백");
		}
		else {
			string ret = data[rear];
			rear = (rear-1 + +MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
};


int main() {
	CircularDeque m, f;
	char gender;
	char fr;
	char num;
	int  line;
	int mc = 0, fc = 0, mf = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		char name[31] = { 0 };
		scanf("%d", &line);
		scanf("%s", name, sizeof(name));
		scanf(" %c", &gender);
		scanf(" %c", &fr);

		if (gender == 'm' && fr == 'F') {
			m.addFront(name);
		}
		else if (gender == 'm' && fr == 'R') {
			m.addRear(name);
		}
		else if (gender == 'f' && fr == 'F') {
			f.addFront(name);
		}
		else if (gender == 'f' && fr == 'R') {
			f.addRear(name);
		}

		if (!m.isEmpty() && !f.isEmpty()) {
			string a = m.deleteFront();
			string b = f.deleteFront();
			printf("Matched : %s %s \n", a.c_str(), b.c_str());
			mf++;
		}

	}
	while (!m.isEmpty()) {
		m.deleteFront();
		mc++;
	}

	while (!f.isEmpty()) {
		f.deleteFront();
		fc++;
	}
	printf("%d %d %d", mf, mc, fc);
	return 0;
}