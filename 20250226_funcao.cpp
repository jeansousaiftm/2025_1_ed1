#include<stdio.h>

int soma(int *a, int *b) {
    printf("%d %d\n", a, b);
    return *a + *b;
}

int main() {
    int a, b;
    printf("%d %d\n", &a, &b);
    scanf("%d %d", &a, &b);
    printf("%d\n", soma(&a, &b));
    printf("%d\n", a);
    return 0;
}
