/*
 * 1. Implemente um programa em C que leia 10 números inteiros informados pelo
 *    usuário e armazene em um vetor. Em seguida, o programa solicita um número a
 *    ser pesquisado e realiza a busca sequencial, informando se o valor foi
 *    encontrado, em que posição, e quantas comparações foram necessárias.
 */

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int v[10], int busca, int *comparacoes) {
    for (int i = 0; i < 10; i++) {
        (*comparacoes)++;
        if (v[i] == busca) {
            return i;
        }
    }
    return -1;
}

int main() {
    int v[10];
    int busca, comparacoes = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o número %i: ", i);
        scanf("%i", &v[i]);
    }

    printf("Digite o número a ser pesquisado: ");
    scanf("%i", &busca);
    int resultado = linearSearch(v, busca, &comparacoes);
    if (resultado != -1) {
        printf("Encontrado o valor %i no índice %i\n", v[resultado], resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }
    printf("Número de comparações realizadas: %d\n", comparacoes);

    return 0;
}
