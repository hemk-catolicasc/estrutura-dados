/*
 * Parte 2 - Busca binária
 *
 * 5. Escreva a versão recursiva da busca binária, a partir da versão iterativa já
 *    testada. O programa lê 10 números, ordena, pesquisa um valor e informa a
 *    posição e a quantidade de chamadas realizadas.
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

int binarySearchRecursiva(int v[], int inicio, int fim, int busca, int *chamadas) {
    (*chamadas)++;
    if (inicio > fim) {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == busca) {
        return meio;
    }

    if (v[meio] < busca) {
        return binarySearchRecursiva(v, meio + 1, fim, busca, chamadas);
    }
    return binarySearchRecursiva(v, inicio, meio - 1, busca, chamadas);
}

int main() {
    int v[10];
    int busca, chamadas = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o número %i: ", i);
        scanf("%i", &v[i]);
    }

    quickSort(v, 0, 9);

    printf("Digite o número a ser pesquisado: ");
    scanf("%i", &busca);
    int resultado = binarySearchRecursiva(v, 0, 9, busca, &chamadas);
    if (resultado != -1) {
        printf("Encontrado o valor %i no índice %i do vetor ordenado\n", busca, resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }
    printf("Número de chamadas realizadas: %d\n", chamadas);

    return 0;
}
