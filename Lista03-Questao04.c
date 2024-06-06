/*
** Função : Imprimir números primos correspondentes
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

bool Primo(int num) {
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
        if (Primo(i) && Primo(num - i)) {
            printf("%d = %d + %d\n", num, i, num - i);
            return;
        }
    }
}

int main() {
    for (int num = 700; num <= 1100; num += 2) {
        encontrarPrimos(num);
    }
    return 0;
}
