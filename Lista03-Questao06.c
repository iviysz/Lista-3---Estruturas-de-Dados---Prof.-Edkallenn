
/*
** Função : Método Newton-Raphson
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>

double calcularRaizQuadrada(double n) {
    double x = n / 2.0;

    while (fabs(x * x - n) > 0.0001) {
        double temp = x;
        x = 0.5 * (x + n / x);
        if (fabs(temp - x) < 0.0001) break;
    }

    return x;
}

int main() {
    double n;

    printf("Digite um numero para calcular a raiz quadrada: ");
    scanf("%lf", &n);

    if (n < 0) {
        printf("Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
    } else {
        double raiz = calcularRaizQuadrada(n);
        printf("A raiz quadrada de %.4lf e aproximadamente %.4lf\n", n, raiz);
    }

    return 0;
}
