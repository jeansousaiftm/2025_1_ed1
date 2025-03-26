#include<stdio.h>

int main() {

    int a;
    scanf("%d", &a);

    printf("v: %d e: %d\n", a, &a);

    int *b = &a;

    printf("v: %d e: %d a: %d\n", b, &b, *b);

    return 0;
}
