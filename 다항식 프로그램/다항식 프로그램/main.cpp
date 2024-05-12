#include <iostream>
#include <iomanip>
using namespace std;

class Node {
private:
	float bo;
	int exp;
	Node* link;
public:
	Node(float b = 0.0, int e = 0) :bo(b), exp(e), link(NULL) {}
	float getbo() {
		return bo;
	}
	Node* getLink() {
		return link;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		if (bo != 0) {
			cout << fixed << setprecision(1) << bo << " x^" << exp;
		}
	}
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removeNext(){
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;
		}
		return removed;
	}
	friend class polyList;
};


class polyList {
private:
	Node org;
public:
	polyList(): org(0){}
	~polyList() { clear(); }
	void clear() {
		while (!isEmpty()) {
			delete remove(0);
		}
	}
	Node* getHead() {
		return org.getLink();

	}
	bool isEmpty() {
		return getHead() == NULL;
	}
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink()) {
			if (n == NULL) {
				break;
			}
		}
		return n;
	}
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;
		}
		return count;
	}
	void add(polyList* pol) {
		polyList b;
		int count = 0;
		Node* p = getHead();
		Node* t = pol->getHead();
		while (p != NULL && t != NULL) {
			if (p->exp == t->exp) {
				b.insert(count++, new Node(p->bo + t->bo, p->exp));
				p = p->getLink();
				t = t->getLink();
			}
			else if (p->exp > t->exp) {
				b.insert(count++, new Node(p->bo, p->exp));
				p = p->getLink();
			}
			else {
				b.insert(count++, new Node(t->bo, t->exp));
				t = t->getLink();
			}
		}
		for (; p != NULL; p = p->getLink()) {
			b.insert(count++, new Node(p->bo, p->exp));
		}
		for (; t != NULL; t = t->getLink()) {
			b.insert(count++, new Node(t->bo, t->exp));
		}
		cout << "(" << b.size() << ") = ";
		b.display();
	}
	void input() {
		int count, e;
		float c;
		cin >> count;
		for (int i = 0; i < count; i++) {
			cin >> c >> e;
			insert(i, new Node(c, e));
		}
	}
	void display() {
		int count = 1;
		if (size() == 0) {
			return;
		}
		else {
			Node* p = getHead();
			while (p->getLink() != NULL) {
				p->display();
				if (p->getbo() != 0) {
					cout << " + ";
				}
				p = p->getLink();
			}
			p->display();
			cout << endl;
		}
	}
};

int main(void) {
	polyList A, B, C;
	A.input();
	B.input();
	cout << "(" << A.size() << ") = ";
	A.display();
	cout << "(" << B.size() << ") = ";
	B.display();
	A.add(&B);
	return 0;
}