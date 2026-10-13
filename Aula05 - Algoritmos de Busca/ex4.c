/*
 * Parte 2 - Busca binária
 *
 * 4. Implemente um programa em C que leia 10 números inteiros, ordene o vetor com
 *    um dos métodos da Unidade II e depois pesquise um valor usando a busca
 *    binária iterativa. Informe se encontrou, em que posição do vetor ordenado, e
 *    quantas comparações foram necessárias.
 */

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int *v, int inicio, int fim) {
    int pivo, i, j;

    pivo = v[fim];
    i = inicio - 1;

    for (j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i + 1], &v[fim]);

    return i + 1;
}

void quickSort(int *v, int inicio, int fim) {
    int posPivo;
    if (inicio < fim) {
        posPivo = particiona(v, inicio, fim);
        quickSort(v, inicio, posPivo - 1);
        quickSort(v, posPivo + 1, fim);
    }
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
    int v[10];
    int busca, comparacoes = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o número %i: ", i);
        scanf("%i", &v[i]);
    }

    quickSort(v, 0, 9);

    printf("Digite o número a ser pesquisado: ");
    scanf("%i", &busca);
    int resultado = binarySearch(v, 0, 9, busca, &comparacoes);
    if (resultado != -1) {
        printf("Encontrado o valor %i no índice %i do vetor ordenado\n", busca, resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }
    printf("Número de comparações realizadas: %d\n", comparacoes);

    return 0;
}
