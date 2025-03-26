#include<stdio.h>
#define MAX_F 10

struct Funcionario {
    char nome[100];
    char cargo[100];
    double salarioBase;
    double beneficios;
    double descontos;
    void ler() {
        printf("Digite o nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o cargo: ");
        scanf("%[^\n]%*c", cargo);
        printf("Digite o salario base: ");
        scanf("%lf%*c", &salarioBase);
        printf("Digite os beneficios: ");
        scanf("%lf%*c", &beneficios);
        printf("Digite os descontos: ");
        scanf("%lf%*c", &descontos);
    }
    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario Base: R$ %.2lf\n", salarioBase);
        printf("Beneficios: R$ %.2lf\n", beneficios);
        printf("Descontos: R$ %.2lf\n", descontos);
        printf("Salario Liquido: R$ %.2lf\n", calcularSalarioLiquido());
    }
    double calcularSalarioLiquido() {
        return salarioBase + beneficios - descontos;
    }
};

struct Loja {
    Funcionario f[MAX_F];
    int ultimo;

    Loja() {
        ultimo = 0;
    }

    void ler() {
        if (ultimo >= MAX_F) {
            printf("Lista de funcionarios cheia.\n");
            return;
        }
        f[ultimo].ler();
        ultimo++;
    }

    void imprimir() {
        for (int i = 0; i < ultimo; i++) {
            f[i].imprimir();
        }
    }

    void mediaSalarial() {
        double total = 0;
        for (int i = 0; i < ultimo; i++) {
            total += f[i].calcularSalarioLiquido();
        }
        printf("Media Salarial: R$ %.2lf\n", total / ultimo);
    }

    void maiorSalario() {
        double maior = 0;
        int posMaior = 0;
        for (int i = 0; i < ultimo; i++) {
            if (f[i].calcularSalarioLiquido() > maior) {
                maior = f[i].calcularSalarioLiquido();
                posMaior = i;
            }
        }
        f[posMaior].imprimir();
    }
};

int main() {
    Loja l;
    int op;
    do {
        printf("1. Ler\n2. Imprimir\n3. Media\n4. Maior\n");
        scanf("%d%*c", &op);
        switch(op) {
        case 1:
            l.ler();
            break;
        case 2:
            l.imprimir();
            break;
        case 3:
            l.mediaSalarial();
            break;
        case 4:
            l.maiorSalario();
            break;
        }
    } while (op == 1 || op == 2 || op == 3 || op == 4);
    return 0;
}
