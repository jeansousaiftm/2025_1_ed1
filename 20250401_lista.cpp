#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* start;
    Node* end;

    List() {
        start = NULL;
        end = NULL;
    }

    bool empty() {
        return start == NULL && end == NULL;
    }

    void pushBack(int value) {
        Node* n = new Node(value);
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    void pushFront(int value) {
        Node* n = new Node(value);
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
    }

};

int main() {

    List l;
    l.pushBack(15);
    l.pushBack(12);
    l.pushBack(5);
    l.pushBack(2);
    l.pushFront(3);
    l.pushFront(9);
    l.print();

    return 0;
}
