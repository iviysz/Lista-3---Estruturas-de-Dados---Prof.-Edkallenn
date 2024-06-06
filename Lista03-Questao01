/*
** Função : Implementar algoritmo que classifica os elementos de um vetor em ordem crescente
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trade(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorSel(int vetor[], int tamanho) {
    int i, j, indice_minimo;

    for (i = 0; i < tamanho-1; i++) {
        indice_minimo = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        trade(&vetor[indice_minimo], &vetor[i]);
    }
}

void gerarVetorAleatorio(int vetor[], int tamanho, int limite_inferior, int limite_superior) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = (rand() % (limite_superior - limite_inferior + 1)) + limite_inferior;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int limite_inferior = 0;
    int limite_superior = 100;
    int vetor[tamanho];

    srand(time(0));

    gerarVetorAleatorio(vetor, tamanho, limite_inferior, limite_superior);

    printf("Vetor: ");
    imprimirVetor(vetor, tamanho);

    ordenarPorSelecao(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);

    return 0;
}
