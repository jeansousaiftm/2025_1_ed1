#include<stdio.h>

struct Node {

    int value;
    int aluno;
    Node* next;

    Node(int _value, int _aluno) {
        value = _value;
        aluno = _aluno;
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
    void pushBack(int value, int aluno) {
        Node* n = new Node(value, aluno);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    int encontrarMaiorNota() {
        if (empty()) return 0;
        int maior = start->value;
        Node *aux = start;
        while (aux != NULL) {
            if (aux->value > maior) {
                maior = aux->value;
            }
            aux = aux->next;
        }
        return maior;
    }

    void print() {
        int maior = encontrarMaiorNota();
        Node *aux = start;
        while (aux != NULL) {
            if (aux->value == maior) {
                printf("%d ", aux->aluno);
            }
            aux = aux->next;
        }
        printf("\n");
    }

};

int main() {


    int n;
    while (scanf("%d", &n) && n > 0) {
        int x, y;
        List l;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            l.pushBack(y, x);
        }
        l.print();
    }

    return 0;
}
