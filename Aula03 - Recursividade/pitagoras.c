#include <stdio.h>
#include <stdlib.h>

// 1. Construa um algoritmo que use recursividade para resolver o problema matemático da série de Pitágoras, sabendo que a série é 1, 3, 6, 10, 15, 21, ...

int pitagoras(int n) {
    if (n <= 1) {
        return n;
    }
    return n + pitagoras(n - 1);
}

int main() {
    int n;

    printf("Digite o Termo da serie de Pitagoras que deseja calcular: ");
    scanf("%i", &n);

    printf("O resultado do termo %i da serie de Pitagoras eh: %i\n", n, pitagoras(n));

    return 0;
}
