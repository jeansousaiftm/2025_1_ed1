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

    void pushPriority(int value) {
        if (value < 65 || end->value >= 65) {
            pushBack(value);
            return;
        }
        if (start->value < 65) {
            pushFront(value);
            return;
        }
        Node *aux = start;
        Node *prev;
        while (aux != NULL) {
            if (aux->value < 65) {
                break;
            }
            prev = aux;
            aux = aux->next;
        }
        Node *n = new Node(value);
        prev->next = n;
        n->next = aux;
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

    List l;
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l.pushPriority(x);
    }
    l.print();
    return 0;
}
