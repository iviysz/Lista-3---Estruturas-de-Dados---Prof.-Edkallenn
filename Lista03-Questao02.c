/*
** Função : Registro de Empregado
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char data_nasc[11];
    char RG[20];
    char data_adm[11];
    double salario;
} Empregado;

void lerDados(Empregado *emp) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", emp->nome);
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf(" %[^\n]", emp->data_nasc);
    printf("Digite o RG: ");
    scanf(" %[^\n]", emp->RG);
    printf("Digite a data de admissao (dd/mm/aaaa): ");
    scanf(" %[^\n]", emp->data_adm);
    printf("Digite o salario: ");
    scanf("%lf", &emp->salario);
}

void exibirDados(Empregado emp) {
    printf("Nome: %s\n", emp.nome);
    printf("Data de Nascimento: %s\n", emp.data_nasc);
    printf("RG: %s\n", emp.RG);
    printf("Data de Admissao: %s\n", emp.data_adm);
    printf("Salario: %.2lf\n", emp.salario);
}

void removerEmpregado(Empregado *emps, int index, int *tamanho) {
    for (int i = index; i < *tamanho - 1; i++) {
        emps[i] = emps[i + 1];
    }
    (*tamanho)--;
    emps = realloc(emps, (*tamanho) * sizeof(Empregado));
}

int main() {
    int opcao, tamanho = 0;
    Empregado *empregados = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar empregado\n");
        printf("2. Listar empregados\n");
        printf("3. Excluir empregado\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                tamanho++;
                empregados = realloc(empregados, tamanho * sizeof(Empregado));
                lerDados(&empregados[tamanho - 1]);
                break;
            case 2:
                for (int i = 0; i < tamanho; i++) {
                    printf("\nEmpregado %d:\n", i + 1);
                    exibirDados(empregados[i]);
                }
                break;
            case 3:
                if (tamanho == 0) {
                    printf("Nenhum empregado para excluir.\n");
                } else {
                    int indice;
                    printf("Digite o indice do empregado a ser excluido (1 a %d): ", tamanho);
                    scanf("%d", &indice);
                    if (indice < 1 || indice > tamanho) {
                        printf("Indice invalido.\n");
                    } else {
                        removerEmpregado(empregados, indice - 1, &tamanho);
                        printf("Empregado excluido.\n");
                    }
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    free(empregados);
    return 0;
}
