#include <iostream>
#include <cstring>

#define MAX_CHAR_PER_LINE 10000

class Line {
    char data[MAX_CHAR_PER_LINE];

public:
    Line(const char* line = "") {
        strcpy(data, line);
    }

    const char* getData() {
        return data;
    }

    void setData(const char* line) {
        strcpy(data, line);
    }
};

class Node {
    Line line;
    Node* next;

public:
    Node(const char* line) : line(line), next(nullptr) {}

    Line getLine() {
        return line;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* node) {
        next = node;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insert(int pos, const char* line) {
        Node* newNode = new Node(line);

        if (pos == 0) {
            newNode->setNext(head);
            head = newNode;
        }
        else {
            Node* prev = getNode(pos - 1);
            if (prev != nullptr) {
                newNode->setNext(prev->getNext());
                prev->setNext(newNode);
            }
        }
    }

    void remove(int pos) {
        if (pos == 0) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
        else {
            Node* prev = getNode(pos - 1);
            if (prev != nullptr && prev->getNext() != nullptr) {
                Node* temp = prev->getNext();
                prev->setNext(temp->getNext());
                delete temp;
            }
        }
    }

    void replace(int pos, const char* line) {
        Node* node = getNode(pos);
        if (node != nullptr) {
            node->getLine().setData(line);
        }
    }

    Node* getNode(int pos) {
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < pos) {
            current = current->getNext();
            index++;
        }
        return current;
    }

    void display() {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            std::cout << index << ": " << current->getLine().getData() << std::endl;
            current = current->getNext();
            index++;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

int main() {
    LinkedList editor;
    char command;
    bool quit = false;

    while (!quit) {
        std::cin >> command;
        switch (command) {
        case 'i': {
            int pos;
            char line[MAX_CHAR_PER_LINE + 1];
            std::cin >> pos;
            std::cin.ignore();
            std::cin.getline(line, MAX_CHAR_PER_LINE);
            editor.insert(pos, line);
            break;
        }
        case 'd': {
            int pos;
            std::cin >> pos;
            editor.remove(pos);
            break;
        }
        case 'r': {
            int pos;
            char line[MAX_CHAR_PER_LINE];
            std::cin >> pos;
            editor.remove(pos);
            std::cin.ignore();
            std::cin.getline(line, MAX_CHAR_PER_LINE);
            editor.insert(pos, line);
            break;
        }
        case 'f': {
            char findStr[MAX_CHAR_PER_LINE];
            char replaceStr[MAX_CHAR_PER_LINE];
            std::cin.ignore();
            std::cin.getline(findStr, MAX_CHAR_PER_LINE);
            std::cin.getline(replaceStr, MAX_CHAR_PER_LINE);
            Node* current = editor.getNode(0);
            int index = 0;
            while (current != nullptr) {
                if (strcmp(current->getLine().getData(), findStr) == 0) {
                    editor.remove(index);
                    editor.insert(index, replaceStr);
                    break;
                }
                current = current->getNext();
                index++;
            }
            break;
        }
        case 'p':
            editor.display();
            std::cout << "EOF" << std::endl;
            break;
        case 'q':
            quit = true;
            break;
        default:
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
