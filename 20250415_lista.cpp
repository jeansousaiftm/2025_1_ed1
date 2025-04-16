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

    //O(n)
    void insert(int v, int p) {

        if (p <= 0) {
            pushFront(v);
            return;
        }

        if (p >= s) {
            pushBack(v);
            return;
        }

        Node *n = new Node(v);
        s++;

        Node *a = start;
        for (int i = 0; i < p - 1; i++) {
            a = a->next;
        }

        n->next = a->next;
        a->next = n;

    }

    //O(n * s)
    void atividade1a(int n) {
        for (int i = 0; i < n; i++) {
            popBack();
        }
    }

    //O(s)
    void atividade1b(int n) {
        if (n < s) {
            Node *aux = start;
            for (int i = 0; i < s - n - 1; i++) {
                aux = aux->next;
            }
            end = aux;
            s -= n;
            for (int i = 0; i < n; i++) {
                Node *toDel = aux->next;
                aux->next = toDel->next;
                delete(toDel);
            }
        } else {
            while (!empty()) {
                popFront();
            }
        }
    }

    //O(1)
    void atividade2() {
        if (s <= 1) return;
        if (s == 2) {
            popBack();
            return;
        }
        Node *second = start->next;
        start->next = second->next;
        delete(second);
        s--;
    }

    void atividade3() {
        pushBack(s);
    }

    void atividade4(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    // O(s)
    void atividade5a(int v) {
        if (s <= 1) return;
        Node* aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }
        Node *n = new Node(v);
        n->next = end;
        aux->next = n;
        s++;
    }

    // O(s)
    void atividade5b(int v) {
        insert(v, s - 1);
    }

};

int main() {

    List l;
    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(3);
    //l.pushBack(5);
    l.pushFront(8);
    l.pushBack(50);
    l.pushFront(78);
    l.pushBack(1);
    l.pushBack(75);
    l.pushFront(25);
    l.pushBack(60);
    l.pushFront(34);
    l.pushBack(80);
    l.pushBack(30);
    l.pushBack(23);
    l.pushFront(5);
    l.pushFront(66);
    l.insert(5, 9);
    l.print();
    l.atividade1b(10);
    l.print();


    return 0;
}
