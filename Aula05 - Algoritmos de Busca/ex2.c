/*
 * 2. Altere a busca sequencial para que ela não pare na primeira ocorrência. O
 *    programa lê 10 números inteiros, pergunta o valor procurado e mostra todas
 *    as posições em que ele aparece, a quantidade total de ocorrências e o número
 *    de comparações.
 */

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int v[10], int busca, int posicoes[10], int *comparacoes) {
    int ocorrencias = 0;
    for (int i = 0; i < 10; i++) {
        (*comparacoes)++;
        if (v[i] == busca) {
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }
    return ocorrencias;
}

int main() {
    int v[10];
    int posicoes[10];
    int busca, comparacoes = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o número %i: ", i);
        scanf("%i", &v[i]);
    }

    printf("Digite o número a ser pesquisado: ");
    scanf("%i", &busca);
    int ocorrencias = linearSearch(v, busca, posicoes, &comparacoes);
    for (int i = 0; i < ocorrencias; i++) {
        printf("Encontrado o valor %i na posição %i\n", busca, posicoes[i]);
    }
    printf("Número de ocorrências do valor %i: %d\n", busca, ocorrencias);
    printf("Número de comparações realizadas: %d\n", comparacoes);

    return 0;
}
