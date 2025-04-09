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
    int s;

    List() {
        start = NULL;
        end = NULL;
        s = 0;
    }

    // O(1)
    bool empty() {
        return start == NULL && end == NULL;
    }

    // O(1)
    void pushBack(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    // O(1)
    void pushFront(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    // O(n)
    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    // O(n)
    /*int size() {
        int s = 0;
        Node* aux = start;
        while (aux != NULL) {
            s++;
            aux = aux->next;
        }
        return s;
    }*/

    // O(1)
    int size() {
        return s;
    }

    // O(1)
    void popFront() {

        if (empty()) return;

        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);
        s--;

    }

    // O(n)
    void popBack() {

        if (empty()) return;

        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }

        delete(end);
        end = aux;
        end->next = NULL;
        s--;

    }

};

int main() {

    List l;
    l.pushBack(15);
    l.pushBack(12);
    l.pushFront(3);
    l.pushFront(9);
    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();


    return 0;
}
