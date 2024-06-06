
/*
** Função : Refazendo número 4
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

bool ePrimo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void encontrarPrimos(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (ePrimo(i) && ePrimo(num - i)) {
            printf("%d = %d + %d\n", num, i, num - i);
            return;
        }
    }
    printf("Não foi possível encontrar %d\n", num);
}

int main() {
    int N;

    printf("Digite um numero inteiro N: ");
    scanf("%d", &N);

    for (int num = 4; num <= N; num += 2) {
        encontrarPrimos(num);
    }

    return 0;
}
