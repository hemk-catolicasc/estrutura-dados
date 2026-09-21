#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);

int main() {
    int num, resultado = 0;

    printf("Digite um numero para calcular a soma dos digitos: ");
    scanf("%i", &num);

    resultado = somaDigitos(num);

    printf("A soma dos digitos de %i é %i\n", num, resultado);

    return 0;
}

int somaDigitos(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + somaDigitos(n / 10);
}