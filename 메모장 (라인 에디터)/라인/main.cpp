#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val = 0) : data(val), prev(nullptr), next(nullptr) {}
};

class LineEditor {
private:
    Node* head;
    Node* cursor;

public:
    LineEditor() {
        head = new Node();
        cursor = head; 
    }

    ~LineEditor() {
        clear();
        delete head;
    }

    void insert(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = cursor->next;
        if (cursor->next)
            cursor->next->prev = newNode;
        newNode->prev = cursor;
        cursor->next = newNode;
        cursor = newNode;
    }

    void moveStart() {
        cursor = head;
    }

    void moveEnd() {
        while (cursor->next)
            cursor = cursor->next;
    }

    void moveLeft() {
        if (cursor != head)
            cursor = cursor->prev;
    }

    void moveRight() {
        if (cursor->next)
            cursor = cursor->next;
    }

    void deleteChar() {
        if (cursor !=head) {
            Node* toDelete = cursor;
            if (toDelete->next) {
                cursor = toDelete->prev;
                toDelete->next->prev = toDelete->prev;
            }
            else {
                cursor = toDelete->prev;
            }
            toDelete->prev->next = toDelete->next;
            delete toDelete;
        }
    }

    void clear() {
        Node* temp = head->next;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head->next = NULL;
        cursor = head;
    }

    string getString() {
        string result;
        Node* temp = head->next;
        while (temp) {
            result += temp->data;
            temp = temp->next;
        }
        return result;
    }
};

int main() {
    string input;
    cin >> input;

    LineEditor editor;
    for (char ch : input) {
        switch (ch) {
        case '^':
            editor.moveStart();
            break;
        case '$':
            editor.moveEnd();
            break;
        case '<':
            editor.moveLeft();
            break;
        case '>':
            editor.moveRight();
            break;
        case '*':
            editor.deleteChar();
            break;
        default:
            editor.insert(ch);
        }
    }

    cout << editor.getString() << endl;

    return 0;
}
