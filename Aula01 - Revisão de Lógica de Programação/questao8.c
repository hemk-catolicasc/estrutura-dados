#include <stdio.h>
#include <stdlib.h>

int main() {

    float vendas[4][3];
    float totalVendas,totalGeral = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("Digite o valor da venda do vendedor %d no mes %d: ", i, j);
            scanf("%f", &vendas[i][j]);
        }
    }

    printf("\nRelatorio de vendas:\n");
    for (int i = 1; i <= 4; i++) {
        totalVendas = 0;
        for (int j = 1; j <= 3; j++) {
            totalVendas += vendas[i][j];
        }
        printf("Total de vendas do vendedor %d: %.2f\n", i, totalVendas);
    }

    for (int j = 1; j <= 3; j++) {
        totalVendas = 0;
        for (int i = 1; i <= 4; i++) {
            totalVendas += vendas[i][j];
        }
        printf("Total de vendas do mes %d: %.2f\n", j, totalVendas);
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 3; j++) {
            totalGeral += vendas[i][j];
        }
    }
    printf("Total geral de vendas: %.2f\n", totalGeral);

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 3; j++) {
            if (vendas[i][j] > vendas[i][j+1]) {
                int aux = vendas[i][j];
                vendas[i][j] = vendas[i][j+1];
                vendas[i][j+1] = aux;
            }
        }
    }
    printf("O vendedor com a maior venda foi o vendedor %d com o valor de %.2f\n", 4, vendas[4][3]);
    return 0;
}