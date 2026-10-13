/*
 * 3. Construa um vetor de 1000 posições preenchido com os valores de 0 a 999, em
 *    ordem. Faça a busca sequencial de três valores: o primeiro elemento, o
 *    último elemento e um valor que não existe no vetor. Mostre quantas
 *    comparações cada busca exigiu e confronte os números com o que se espera do
 *    método.
 */

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int v[], int n, int busca, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == busca) {
            return i;
        }
    }
    return -1;
}

int main() {
    int v[1000];
    for (int i = 0; i < 1000; i++) {
        v[i] = i;
    }

    int buscas[3] = {0, 999, 1000};
    char *descricoes[3] = {"primeiro elemento", "último elemento", "valor inexistente"};
    int esperadas[3] = {1, 1000, 1000};

    for (int i = 0; i < 3; i++) {
        int comparacoes = 0;
        int resultado = linearSearch(v, 1000, buscas[i], &comparacoes);
        printf("Busca do %s (%i): ", descricoes[i], buscas[i]);
        if (resultado != -1) {
            printf("encontrado no índice %i", resultado);
        } else {
            printf("não encontrado");
        }
        printf(", %d comparações (esperado: %d)\n", comparacoes, esperadas[i]);
    }

    return 0;
}
