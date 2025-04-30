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


    void inserirCrescente(int value) {
        if (empty()) {
            pushBack(value);
            return;
        }
        if (value < start->value) {
            pushFront(value);
            return;
        }
        if (value > end->value) {
            pushBack(value);
            return;
        }
        Node *aux = start;
        Node *prev;
        while (aux != NULL) {
            if (aux->value > value) {
                break;
            }
            prev = aux;
            aux = aux->next;
        }
        Node *n = new Node(value);
        prev->next = n;
        n->next = aux;
        s++;
    }

    void inserirDecrescente(int value) {
        if (empty()) {
            pushBack(value);
            return;
        }
        if (value > start->value) {
            pushFront(value);
            return;
        }
        if (value < end->value) {
            pushBack(value);
            return;
        }
        Node *aux = start;
        Node *prev;
        while (aux != NULL) {
            if (aux->value < value) {
                break;
            }
            prev = aux;
            aux = aux->next;
        }
        Node *n = new Node(value);
        prev->next = n;
        n->next = aux;
        s++;
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

};

int main() {

    List pares, impares;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares.inserirCrescente(x);
        } else {
            impares.inserirDecrescente(x);
        }
    }
    pares.print();
    impares.print();


    return 0;
}
