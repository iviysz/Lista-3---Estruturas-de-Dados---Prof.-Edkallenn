
/*
** Função : 
** Autor : Thiago Henrique Paiva de Sousa
** Data : 05/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imaginaria;
} Complexo;

Complexo* criarComplexo(double real, double imaginaria) {
    Complexo *numeroComplexo = (Complexo*)malloc(sizeof(Complexo));
    if (numeroComplexo != NULL) {
        numeroComplexo->real = real;
        numeroComplexo->imaginaria = imaginaria;
    }
    return numeroComplexo;
}

void destruirComplexo(Complexo *numeroComplexo) {
    free(numeroComplexo);
}

void lerComplexo(Complexo *numeroComplexo) {
    printf("Digite a parte real: ");
    scanf("%lf", &numeroComplexo->real);
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &numeroComplexo->imaginaria);
}

void somarComplexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
    resultado->real = num1->real + num2->real;
    resultado->imaginaria = num1->imaginaria + num2->imaginaria;
}

void subtrairComplexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
    resultado->real = num1->real - num2->real;
    resultado->imaginaria = num1->imaginaria - num2->imaginaria;
}

void multiplicarComplexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
    resultado->real = num1->real * num2->real - num1->imaginaria * num2->imaginaria;
    resultado->imaginaria = num1->real * num2->imaginaria + num1->imaginaria * num2->real;
}

void dividirComplexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
    double denominador = num2->real * num2->real + num2->imaginaria * num2->imaginaria;
    resultado->real = (num1->real * num2->real + num1->imaginaria * num2->imaginaria) / denominador;
    resultado->imaginaria = (num1->imaginaria * num2->real - num1->real * num2->imaginaria) / denominador;
}

void mostrarComplexo(Complexo *numeroComplexo) {
    printf("(%lf,%lf)\n", numeroComplexo->real, numeroComplexo->imaginaria);
}

int main() {
    Complexo *num1, *num2, *resultado;
    
    // Criando dois números complexos
    num1 = criarComplexo(2.0, 3.0);
    num2 = criarComplexo(1.0, -2.0);
    resultado = criarComplexo(0.0, 0.0);

    // Operações
    somarComplexos(resultado, num1, num2);
    printf("Soma: ");
    mostrarComplexo(resultado);

    subtrairComplexos(resultado, num1, num2);
    printf("Subtracao: ");
    mostrarComplexo(resultado);

    multiplicarComplexos(resultado, num1, num2);
    printf("Multiplicacao: ");
    mostrarComplexo(resultado);

    dividirComplexos(resultado, num1, num2);
    printf("Divisao: ");
    mostrarComplexo(resultado);

    // Liberando a memória alocada
    destruirComplexo(num1);
    destruirComplexo(num2);
    destruirComplexo(resultado);

    return 0;
}
