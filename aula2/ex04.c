/*
 * 4. Construa um programa em C ANSI que leia a, b e c (com a != 0) e
 *    calcule as raizes da equacao do 2o grau usando uma funcao
 *    bhaskara(float a, float b, float c, float *x1, float *x2) que grave
 *    os valores em *x1 e *x2, tratando delta < 0 com uma mensagem
 *    "sem raizes reais".
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bhaskara(float a, float b, float c, float *x1, float *x2) {
    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("sem raizes reais\n");
        return 0;
    }

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return 1;
}

int main(void)
{
    float a, b, c, x1, x2;

    printf("Digite os valores de a, b e c (com a != 0)\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("a deve ser diferente de 0\n");
        return 1;
    }

    if (bhaskara(a, b, c, &x1, &x2)) {
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }

    return 0;
}
