/*
 * 6. Construa um programa em C ANSI que leia dois inteiros a e b e
 *    implemente tres funcoes void somar(int *a, int *b, int *res),
 *    void subtrair(int *a, int *b, int *res) e
 *    void multiplicar(int *a, int *b, int *res) que recebam entradas por
 *    ponteiro e gravem o resultado em *res, imprimindo os tres resultados
 *    no main.
 */

#include <stdio.h>
#include <stdlib.h>

void somar(int *a, int *b, int *res) {
    *res = *a + *b;
}

void subtrair(int *a, int *b, int *res) {
    *res = *a - *b;
}

void multiplicar(int *a, int *b, int *res) {
    *res = *a * *b;
}

int main(void)
{   
    int a, b, soma, subtracao, multiplicacao;
    printf("Digite dois inteiros:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    somar(&a, &b, &soma);
    subtrair(&a, &b, &subtracao);
    multiplicar(&a, &b, &multiplicacao);

    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", subtracao);
    printf("Multiplicacao: %d\n", multiplicacao);
    
    return 0;
}
