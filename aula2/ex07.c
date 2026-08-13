/*
 * 7. Construa um programa em C ANSI que leia um inteiro positivo n e
 *    calcule o fatorial usando uma funcao void fatorial(int n, double *fat)
 *    que grave o resultado em *fat, validando n >= 0 antes do calculo.
 */

#include <stdio.h>
#include <stdlib.h>

void fatorial(int n1, double *fat) {
    *fat = 1;
    for (int i = 2; i <= n1; i++) {
        *fat *= i;
    }
}

int main(void)
{   
    int n1;
    double fat;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n1);

    if (n1 < 0) {
        printf("Numero invalido\n");
        return 1;
    }

    fatorial(n1, &fat);
    printf("Fatorial de %d = %.0f\n", n1, fat);


    return 0;
}
