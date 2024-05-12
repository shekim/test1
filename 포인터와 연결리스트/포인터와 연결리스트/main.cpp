#include<iostream>
#include<string>
#include<cstring> // strcpy_s를 사용하기 위해 필요

#define MAX 15

class Student {
    int id;
    char name[MAX];
    char dept[MAX];
public:
    Student(int i = 0, const char* n = "", const char* d = "") {
        set(i, n, d);
    }
    void set(int i, const char* n, const char* d) {
        id = i;
        strcpy_s(name, MAX, n);
        strcpy_s(dept, MAX, d);
    }
};

class Node : public Student {
    Node* link;
public:
    Node(int i = 0, const char* n = "", const char* d = "")
        : Student(i, n, d) {
        link = NULL;
    }
    ~Node() {}
    Node* getLink() {
        return link;
    }
    void setLink(Node* p) {
        link = p;
    }
};

class LinkedStack {
    Node* top;
public:
    LinkedStack() {
        top = NULL;
    }
    ~LinkedStack() {
        while (!isEmpty()) delete pop();
    }
    bool isEmpty() {
        return top == NULL;
    }
    void push(Node* p) {
        if (isEmpty()) {
            top = p;
        }
        else {
            p->setLink(top);
            top = p;
        }
    }
    Node* pop() {
        if (isEmpty()) {
            return NULL;
        }
        Node* p = top;
        top = top->getLink();
        return p;
    }
    Node* peek() {
        return top;
    }

};


int main() {
    LinkedStack stk;
    stk.push(new Node(2021, "가나다", "컴공"));
    stk.push(new Node(2021, "나다가", "수학"));
    stk.push(new Node(2021, "카나다", "재무"));
    Node* node = stk.pop();
}