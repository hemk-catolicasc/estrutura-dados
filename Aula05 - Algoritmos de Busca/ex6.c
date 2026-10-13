/*
 * Parte 2 - Busca binária
 *
 * 6. Construa um vetor ordenado de 1000 posições com os valores de 0 a 999.
 *    Pesquise o primeiro elemento, o último e um valor ausente, usando a busca
 *    sequencial e a busca binária, e mostre os contadores das duas lado a lado.
 *    Confronte os números com n e com log n na base 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linearSearch(int v[], int n, int busca, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == busca) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int v[], int inicio, int fim, int busca, int *comparacoes) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        (*comparacoes)++;
        if (v[meio] == busca) {
            return meio;
        }

        if (v[meio] < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
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
    char *descricoes[3] = {"primeiro", "último", "ausente"};

    printf("Valor\tSequencial\tBinária\tCaso\n");
    for (int i = 0; i < 3; i++) {
        int compSequencial = 0, compBinaria = 0;
        linearSearch(v, 1000, buscas[i], &compSequencial);
        binarySearch(v, 0, 999, buscas[i], &compBinaria);
        printf("%i\t%d\t\t%d\t%s\n", buscas[i], compSequencial, compBinaria, descricoes[i]);
    }

    printf("\nn = 1000\n");
    printf("log2(n) = %.2f\n", log2(1000));

    return 0;
}
