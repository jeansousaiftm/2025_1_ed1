#include<stdio.h>
#include <time.h>
#define MAX_C 50

struct Data {
    int dia, mes, ano;

    void ler() {
        printf("Digite o dia: ");
        scanf("%d%*c", &dia);
        printf("Digite o mes: ");
        scanf("%d%*c", &mes);
        printf("Digite o ano: ");
        scanf("%d%*c", &ano);
    }

    void imprimir() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {
        time_t mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        int diah = tm.tm_mday;
        int mesh = tm.tm_mon + 1;
        int anoh = tm.tm_year + 1900;
        if (mes > mesh || (mes == mesh && dia > diah)) {
            return (anoh - ano) - 1;
        }
        return anoh - ano;
    }
};

struct Cliente {
    char sexo;
    Data nascimento;
    int idade;
    char nome[100];
    void ler() {
        printf("Digite o nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o sexo: ");
        scanf("%c%*c", &sexo);
        nascimento.ler();
        idade = nascimento.calcularIdade();
    }
    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        nascimento.imprimir();
        printf("Idade: %d\n", idade);
    }
};

int main() {
    int op, ultimo = 0;
    Cliente c[MAX_C];
    do {
        printf("1. Cadastrar\n2. Listar\n");
        scanf("%d%*c", &op);
        switch(op) {
        case 1:
            if (ultimo >= MAX_C) {
                printf("Nao e possivel cadastrar mais clientes\n");
                break;
            }
            c[ultimo].ler();
            ultimo++;
            break;
        case 2:
            for (int i = 0; i < ultimo; i++) {
                c[i].imprimir();
            }
        }
    } while (op == 1 || op == 2);
    return 0;
}
