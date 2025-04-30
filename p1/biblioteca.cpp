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

    int livro(int tp) {
        if (tp == 0) return 0;
        int c = 1;
        Node *aux = start;
        while (aux != NULL) {
            if (tp < aux->value) {
                return c;
            }
            tp -= aux->value;
            c++;
            aux = aux->next;
        }
        return 0;
    }

};

int main() {

    List l;
    int n, x, tp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
    }
    scanf("%d", &tp);
    printf("%d\n", l.livro(tp));
    return 0;
}
