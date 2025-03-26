#include<stdio.h>
#define MAX_L 10

struct Livro {
    char nome[100];
    char autor[100];
    int numPaginas;
    void ler() {
        printf("Digite o nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite o num de paginas: ");
        scanf("%d%*c", &numPaginas);
    }

    void imprimir(){
        printf("Nome: %s\n", nome);
        printf("Autor: %s\n", autor);
        printf("Num Paginas: %d\n", numPaginas);
    }
};

struct Biblioteca {
    Livro l[MAX_L];
    int ultimo;

    Biblioteca() {
        ultimo = 0;
    }

    void ler() {
        if (ultimo >= MAX_L) {
            printf("Biblioteca cheia\n");
            return;
        }
        l[ultimo].ler();
        ultimo++;
    }

    void imprimir() {
        for (int i = 0; i < ultimo; i++) {
            l[i].imprimir();
        }
    }

    void maiorNumPaginas() {
        int maior = 0;
        int posMaior = 0;
        for (int i = 0; i < ultimo; i++) {
            if (l[i].numPaginas > maior) {
                maior = l[i].numPaginas;
                posMaior = i;
            }
        }
        l[posMaior].imprimir();
    }
};


int main() {
    Biblioteca b;
    int op;
    do {
        printf("1. Ler\n2. Imprimir\n3. Maior\n");
        scanf("%d%*c", &op);
        switch(op) {
        case 1:
            b.ler();
            break;
        case 2:
            b.imprimir();
            break;
        case 3:
            b.maiorNumPaginas();
            break;
        }
    } while (op == 1 || op == 2 || op == 3);
    return 0;
}
