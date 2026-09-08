#include <stdio.h>
#include <stdlib.h>

// 2. Implemente uma função recursiva em C ANSI que calcule o número de elementos pares em um vetor de inteiros.

int contarPares(int v[], int n) {
    if (n == 0) {
        return 0;
    }
    return (v[n - 1] % 2 == 0) + contarPares(v, n - 1);
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);
    int v[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %i do vetor: ", i + 1);
        scanf("%i", &v[i]);
    }

    printf("O numero de elementos pares no vetor eh: %i\n", contarPares(v, n));

    return 0;
}
