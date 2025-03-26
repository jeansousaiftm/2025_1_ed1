/*
Criar uma função que recebe:
2 valores que são as dimensões de um retângulo
2 ponteiros para armazenar area e perimetro
retornar nos ponteiros o cálculo de área e
perímetro
*/

#include<stdio.h>

void calcular(int l1, int l2, int *a, int *p) {
    *a = l1 * l2;
    *p = (l1 + l2) * 2;
}

int main() {

    int l1, l2, a, p;
    scanf("%d %d", &l1, &l2);
    calcular(l1, l2, &a, &p);

    printf("%d %d\n", a, p);

    return 0;
}
