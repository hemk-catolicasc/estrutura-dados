/*
 * 8. Construa um programa em C ANSI que leia tres inteiros a, b e c e
 *    ordene em ordem crescente usando uma funcao
 *    void ordenar3(int *a, int *b, int *c) que faca as trocas por
 *    referencia e depois imprima os valores ordenados.
 */

#include <stdio.h>
#include <stdlib.h>

void ordenar3(int *a, int *b, int *c) {
    int temp;
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void)
{   
    int a, b, c;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);

    ordenar3(&a, &b, &c);

    printf("Numeros em ordem crescente: %d, %d, %d\n", a, b, c);

    return 0;
}
