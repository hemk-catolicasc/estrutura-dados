#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int main() {

    int num, resultado = 0;

    printf("Digite um numero para calcular o fatorial: ");
    scanf("%i", &num);

    resultado = fatorial(num);

    printf("O fatorial de %i é %i\n", num, resultado);

    return 0;
}