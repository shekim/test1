#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define MAX_QUEUE_SIZE 11

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}
class CircularQueue {
protected:
	int front;
	int rear;
	char data[MAX_QUEUE_SIZE];
public:
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	void enqueue(char val) {
		if (isFull()) {
			error("error:큐가 포화상태입니다\n");
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	char dequeue() {
		if (isEmpty()) {
			error(" error: 큐가 공백상태입니다\n");
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	char peek() {
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
	void addRear(char val) {
		enqueue(val);
	}
	char deleteFront() {
		return dequeue();
	}
	char getFront() {
		return peek();
	}
	char getRear() {
		if (isEmpty()) {
			error("공백");
		}
		else {
			return data[rear];
		}
	}
	void addFront(char val) {
		if (isFull()) {
			error("포화");
		}
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	char deleteFear() {
		if (isEmpty()) {
			error("공백");
		}
		else {
			char ret = data[rear];
			rear = (rear - 1 + +MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
};


int main() {
	CircularDeque U, R;

	int i = 0;
	char az;
	while ((az = getchar()) != '\n') {
		if(az == ' ') {
		}
		else if (az == 'U') {
			if (U.isEmpty()) {
				printf("ERROR");
				return 0;
			}
			else {
				R.addRear(U.deleteFear());

			}
		}
		else if (az == 'R') {
			if (R.isEmpty()) {
				printf("ERROR");
				return 0;
			}
			else {
				U.addRear(R.deleteFear());
			}
		}
		else {
			if (!R.isEmpty()) {
				while (!R.isEmpty()) {
					R.deleteFear();
				}
				U.addRear(az);
			}
			else {
				if (U.isFull()) {
					U.deleteFront();
					U.addRear(az);
				}
				else {
					U.addRear(az);
				}
			}
		}


	}
	//끝나면 결과출력
	if (!U.isEmpty()) {
		while (!U.isEmpty()) {
			printf("%c ", U.deleteFear());
		}
		printf("\n");
	} 
	else {
		printf("EMPTY\n");
	}

	if (!R.isEmpty()) {
		while (!R.isEmpty()) {
			printf("%c ", R.deleteFear());
		}
	}
	else {
		printf("EMPTY");
	}

	return 0;
}