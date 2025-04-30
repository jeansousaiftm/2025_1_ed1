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
    Node* median;
    int s;

    List() {
        start = NULL;
        median = NULL;
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
            median = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
        if (s % 2 == 1) {
            median = median->next;
        }
    }

    double medianValue() {
        if (s % 2 == 1) {
            return median->value;
        } else {
            return (median->value + median->next->value) / 2.0;
        }
    }

    // O(n)
    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("%.2lf\n", medianValue());
    }

};

int main() {

    List l;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
        l.print();
    }

    return 0;
}
